#pragma once

template<typename TValue>
class MemoryVector
{
public:
    MemoryVector() {}
    MemoryVector(std::list<TValue>& xList) { m_Container = xList; m_It = m_Container.begin(); }
    MemoryVector(std::vector<TValue>& xList) { m_Container = xList; m_It = m_Container.begin(); }
    MemoryVector(const MemoryList<TValue>& xMsList) { m_Container = xMsList.m_Container; m_It = m_Container.begin(); }
    MemoryVector(const MemoryVector<TValue>& xMsList) { m_Container = xMsList.m_Container; m_It = m_Container.begin(); }
    void operator=(std::list<TValue>& xList) { m_Container = xList; m_It = m_Container.begin(); }
    void operator=(std::vector<TValue>& xList) { m_Container = xList; m_It = m_Container.begin(); }
    void operator=(MemoryList<TValue>& xMsList) { m_Container = xMsList.m_Container; m_It = m_Container.begin(); }
    void operator=(MemoryVector<TValue>& xMsList) { m_Container = xMsList.m_Container; m_It = m_Container.begin(); }
    TValue& operator [](Int32 xIndex) { return m_Container[xIndex]; }

    Int32 IndexOf(TValue value)
    {
        Int32 xIndex = 0;
        for (std::vector<TValue>::iterator it = m_Container.begin(); it != m_Container.end(); ++it, xIndex++) { if (*it == value) { return xIndex; } }
        return -1;
    }
    Int32 GetCount() { return (Int32)m_Container.size(); }
    Int64 GetBigCount() { return (Int64)m_Container.size(); }

    auto GetFirst() { return m_Container.begin(); }
    auto GetLast() { return m_Container.size() > 0 ? m_Container.end() - 1 : m_Container.end(); }
    TValue GetValue() { return *m_It; }
    TValue& Value() { return *m_It; }
    TValue& ValueToFirst() { this->ToFirst(); return Value(); }

    bool BeginLoop() { return (m_It = m_Container.begin()) != m_Container.end(); }
    bool Next() { return m_It != m_Container.end() ? (++m_It) != m_Container.end() : false; }

    auto& ToFirst() { m_It = m_Container.begin(); return (*this); }
    auto& ForFirst() { m_It = m_Container.begin(); return (*this); }
    auto& ToLast() { m_It = m_Container.size() > 0 ? m_Container.end() - 1 : m_Container.end(); return (*this); }
    auto& ForLast() { m_It = m_Container.size() > 0 ? m_Container.end() - 1 : m_Container.end(); return (*this); }
    auto& ToEnd() { m_It = m_Container.end(); return (*this); }

    Boolean Empty() { return m_Container.empty(); }
    Boolean IsValid() { return m_It != m_Container.end(); }
    Boolean IsBegin() { return m_It == m_Container.begin(); }
    Boolean IsEnd() { return m_It == m_Container.end(); }

    void Add(TValue value) { this->AddToLast(value); }
    void AddToLast(TValue value)
    {
        m_Container.emplace_back(value);
        m_It = m_Container.begin();
    }
    void AddToFirst(TValue value)
    {
        m_Container.emplace_front(value);
        m_It = m_Container.begin();
    }

    void RemoveCur() { if (m_Container.size() == 0) { return; } if (m_It != m_Container.end()) { m_It = m_Container.erase(m_It); } }
    void Remove(TValue value)
    {
        if (m_Container.size() == 0) { return; }
        if (m_It != m_Container.end() && *m_It == value) { m_It = m_Container.erase(m_It); }
        else { m_Container.erase(value); }
    }

    TValue RemoveGetFirst() { TValue xFirst = *(m_Container.begin()); RemoveAtFirst(); return xFirst; }
    void RemoveAtFirst()
    {
        if (m_It == m_Container.begin()) { m_It = m_Container.erase(m_It); }
        else { m_Container.erase(m_Container.begin()); }
    }
    TValue RemoveGetLast() { TValue xLast = *(m_Container.begin()); RemoveAtLast(); return xLast; }
    void RemoveAtLast()
    {
        auto it = m_Container.end(); it--;
        if (m_It == it) { m_It = m_Container.erase(m_It); }
        else { m_Container.erase(it); }
    }
    void RemoveAt(Int32 xIndex)
    {
        auto xIt = m_Container.begin();
        for (Int32 i = 0; i < xIndex; i++) { ++xIt; }
        m_Container.erase(xIt);
    }

    void Clear() { m_It = m_Container.end(); m_Container.clear(); }

    Boolean MoveUp() { return --m_It != m_Container.end(); }
    Boolean MoveNext() { return ++m_It != m_Container.end(); }

    TValue& ValueDirectMoveUp() { --m_It; return Value(); }
    void DirectMoveUp() { --m_It; }
    void DirectMoveNext() { ++m_It; }
    void SafeMoveUp() { if (m_Container.size() > 0 && m_It != m_Container.begin() && m_It != m_Container.end()) { --m_It; } }
    void SafeMoveNext() { if (m_Container.size() > 0 && m_It != m_Container.end()) { ++m_It; } }
public:
    std::vector<TValue> m_Container;
    typename std::vector<TValue>::iterator m_It;
};
