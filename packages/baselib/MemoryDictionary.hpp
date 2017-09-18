#pragma once

template<typename TKey, typename TValue>
class MemoryDictionary
{
public:
    MemoryDictionary() { }
    bool ContainsKey(TKey key) { return m_Container.find(key) != m_Container.end(); }
    Int32 GetCount() { return (Int32)m_Container.size(); }
    Int64 GetBigCount() { return (Int64)m_Container.size(); }

    auto GetFirst() { return m_Container.begin(); }
    auto GetLast() { return m_Container.size() > 0 ? m_Container.end() - 1 : m_Container.end(); }
    TKey GetKey() { return m_It->first; }
    TValue GetValue() { return m_It->second; }
    TValue GetValue(TKey key) { std::map<TKey, TValue>::iterator it = m_Container.find(key); if (it != m_Container.end()) { return it->second; } else { return NULL; } }
    TValue& operator [](TKey key)
    {
        if (m_Container.size() == 0)
        {
            TValue& xRet = m_Container[key];
            m_It = m_Container.begin();
            return xRet;
        }
        else
        {
            return m_Container[key];
        }
    }
    TKey Key() { return m_It->first; }
    TValue& Value() { return m_It->second; }
    TValue& ValueToFirst() { this->ToFirst(); return Value(); }

    bool BeginLoop() { return (m_It = m_Container.begin()) != m_Container.end(); }
    bool Next() { return m_It != m_Container.end() ? (++m_It) != m_Container.end() : false; }

    auto& ToFirst() { m_It = m_Container.begin(); return (*this); }
    auto& ForFirst() { m_It = m_Container.begin(); return (*this); }
    auto& ToLast() { m_It = m_Container.size() > 0 ? m_Container.end() - 1 : m_Container.end(); return (*this); }
    auto& ForLast() { m_It = m_Container.size() > 0 ? m_Container.end() - 1 : m_Container.end(); return (*this); }
    auto& ToEnd() { m_It = m_Container.end(); return (*this); }

    bool Empty() { return m_Container.empty(); }
    bool IsValid() { return m_It != m_Container.end(); }
    bool IsBegin() { return m_It == m_Container.begin(); }
    bool IsEnd() { return m_It == m_Container.end(); }

    void Add(TKey key, TValue value)
    {
        if (m_Container.size() == 0)
        {
            m_Container.insert(std::pair<TKey, TValue>(key, value));
            m_It = m_Container.begin();
        }
        else
        {
            m_Container.insert(std::pair<TKey, TValue>(key, value));
        }
    }
    void RemoveCur() { if (m_Container.size() == 0) { return; } if (m_It != m_Container.end()) { m_It = m_Container.erase(m_It); } }
    void Remove(TKey xKey) { if (m_Container.size() == 0) { return; } if (m_It != m_Container.end() && m_It->first == xKey) { m_It = m_Container.erase(m_It); } else { m_Container.erase(xKey); } }
    void Clear() { m_It = m_Container.end(); m_Container.clear(); }

    bool MoveUp() { return --m_It != m_Container.end(); }
    bool MoveNext() { return ++m_It != m_Container.end(); }

    TValue& ValueDirectMoveUp() { --m_It; return Value(); }
    void DirectMoveUp() { --m_It; }
    void DirectMoveNext() { ++m_It; }
    void SafeMoveUp() { if (m_Container.size() > 0 && m_It != m_Container.begin() && m_It != m_Container.end()) { --m_It; } }
    void SafeMoveNext() { if (m_Container.size() > 0 && m_It != m_Container.end()) { ++m_It; } }
public:
    std::map<TKey, TValue> m_Container;
    typename std::map<TKey, TValue>::iterator m_It;
};

