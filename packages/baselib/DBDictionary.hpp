#pragma once

template<class TFreezeMap>
class DBDictionary
{
public:
    typename typedef TFreezeMap::value_type::first_type _TKey;
    typename typedef TFreezeMap::value_type::second_type _TValue;
    typename typedef TFreezeMap::iterator _DBIterator;

    class DBIterator
    {
    public:
        DBIterator(TFreezeMap& dbMap, _DBIterator& xIterator)
            : m_dbMap(dbMap)
            , m_Iterator(xIterator)
        {

        }

        void operator =(_TValue& xValue)
        {
            m_Iterator.set(xValue);
        }

        operator _TValue() const
        {
            return (*m_Iterator).second;
        }

        bool Begin() { return (m_Iterator = m_dbMap.begin()) != m_dbMap.end(); }
        bool Next() { return (++m_Iterator) != m_dbMap.end(); }
        _TKey GetKey() { return m_Iterator->first; }
        _TValue GetValue() { return m_Iterator->second; }

    private:
        friend class DBDictionary;
        _DBIterator m_Iterator;
        TFreezeMap& m_dbMap;
    };
public:

    DBDictionary(const Freeze::ConnectionPtr& xConnection, const std::string& xDataName)
        : m_dbMap(xConnection, xDataName)
        , m_dbIt(m_dbMap.end())
    {

    }


    bool ContainsKey(_TKey key)
    {
        return m_dbMap.find(key) != m_dbMap.end();
    }

    void Add(_TKey key, _TValue value)
    {
        m_dbMap.insert(make_pair(key, value));
    }

    void Remove(_TKey key)
    {
        if (m_dbIt != m_dbMap.end() && m_dbIt->first == key)
        {
            m_dbMap.erase(m_dbIt);
            ++m_dbIt;
        }
        else
        {
            m_dbMap.erase(key);
        }
    }

    void Clear()
    {
        m_dbMap.clear();
    }

    int GetCount()
    {
        return (int)m_dbMap.size();
    }

    //DBIterator operator [](_TKey key)
    //{
    //    if (!this->ContainsKey(key))
    //    {
    //        _TValue xTempValue;
    //        this->Add(key, xTempValue);
    //    }
    //    return DBIterator(this->m_dbMap, m_dbMap.find(key));
    //}

    _TValue GetValue(_TKey key)
    {
        _DBIterator it = m_dbMap.find(key);
        if (it != m_dbMap.end())
        {
            return it->second;
        }
        throw "no this value";
    }

    //_TKey GetLastKey() { return (--(m_dbMap.end()))->first; }
    //_TValue GetLastValue() { return (--(m_dbMap.end()))->second; }

    bool BeginLoop() { return (m_dbIt = m_dbMap.begin()) != m_dbMap.end(); }
    bool Next()
    {
        return m_dbIt != m_dbMap.end() ? (++m_dbIt) != m_dbMap.end() : false;
    }
    _TKey GetKey() { return m_dbIt->first; }
    _TValue GetValue() { return m_dbIt->second; }

private:
    _DBIterator m_dbIt;
    TFreezeMap m_dbMap;
};
