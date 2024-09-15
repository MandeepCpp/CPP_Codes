/*
DeCo Dev Candidate Technical Interview

C++ code sample
Question 1 : We have a device that sends ASCII messages with the following structure:
            <START_DELIMITER><LENGTH><KEY=VALUE><END_DELIMITER>
            An example of such a message is ‘+05AA=11-‘. <START_DELIMITER> is ’+’, <END_DELIMITER> is  ‘-‘,
            and <LENGTH> is a two characters representation of the length of the <KEY=VALUE> element. The total length of this message is 7.
            •	What is the maximum total length of a message?

            Answer :
            START_DELIMITER: 1 character
            LENGTH: 2 characters
            KEY=VALUE: 99 characters (maximum length)
            END_DELIMITER: 1 character
            Adding these together gives:

            1 + 2  +  99 + 1 = 103 characters
            1+2+99+1=103 characters

Question2 : We have a legacy class CProtocol that appends incoming data from a device on a buffer.
            Some methods of the CProtocol class handling the parsing of the buffer need to be refactored to enhance readability.
            The data buffer is stored within the class as BYTE* m_data.
            The length of the buffer is int m_size. Suppose you have a class Buffer<BYTE>, equivalent to a const std::vector<BYTE> that wraps a BYTE array.

            •	Propose a solution that allows to find a message start delimiter within a buffer?
            To make the code reusable, we have to handle message start delimiters that are more than one character long.
            •	Can you expand your solution to make that possible?
The purpose of the parsing is to return a Buffer<BYTE> object that represents a message.
•	Give the signature of the “Parse” method?
•	Explain how you would do the message parsing?
C++ language
•	What is the last thing you learned about C++?
•	What is the difference between a "struct" and a "class"?
•	What is the purpose of "const"?
•	Do you know about RAII?
•	What are the two main features introduced or enhanced in C++ 11/14/17/20 and why?
•	What are you expecting the most from future evolutions of the language?
 C# language
•	What are the differences and constraints in usage between "ref" and "out"?
•	What are the differences and constraints in usage between "readonly" and "const"?
•	Can you explain the principles behind boxing and unboxing?
C++ code review
Peter has written some code to implement something. You have been tasked to review his code.
•	What remarks would you make regarding the code (old code is highlighted in grey) ?
class CTimer
{
    CTimer(int id, CObject* pObj) : m_TimerID(id), m_pObject(pObj) {}
    int m_TimerID;
    CObject* m_pObject;

    // ...
};

class CObject
{
    // ...

    bool Exists(int id)
    {
        bool ok = false;
        for (auto it = m_timerIDs.begin(); it != m_timerIDs.end(); it++)
        {
            if (it->m_TimerID == id)
            {
                ok = true;
                return true;
            }
        }
        return ok;
    }

    void AddTimer(int id)
    {
        if (!Exists(id))
        {
            m_timerIDs.push_back(new CTimer(id, this));
        }
    }

    void RemoveTimer(int id)
    {
        for (auto it = m_timerIDs.begin(); it != m_timerIDs.end(); it++)
        {
            if (it->m_TimerID == id)
            {
delete *it;
                it = m_timerIDs.erase(it);
            }
        }
    }

    // ...

private:
    int m_Value = 0;
    std::vector<CTimer*> m_timerIDs;
}


*/

#include <iostream>
#include <vector>
#include <cstring>
#include <memory>
#include <algorithm>

using namespace std;

typedef signed char BYTE;
template <typename T>
class Buffer
{
    const T *m_data;
    size_t m_size;

public:
    Buffer(const T *data, size_t size) : m_data(data), m_size(size) {}

    const T *data() const { return m_data; }
    size_t size() const { return m_size; }

    Buffer<T> subbuffer(size_t offset, size_t length) const
    {
        return Buffer<T>(m_data + offset, length);
    }
};

class CProtocol
{
public:
    // Parses the buffer starting from `start` index, looking for the delimiter `delimiter`
    // Returns a Buffer<BYTE> representing the message, or an empty Buffer if not found
    Buffer<BYTE> Parse(const Buffer<BYTE> &buffer, const Buffer<BYTE> &delimiter);
};

Buffer<BYTE> CProtocol::Parse(const Buffer<BYTE> &buffer, const Buffer<BYTE> &delimiter)
{
    const BYTE *data = buffer.data();
    size_t dataSize = buffer.size();
    const BYTE *del = delimiter.data();
    size_t delSize = delimiter.size();

    // Look for the delimiter in the buffer
    for (size_t i = 0; i <= dataSize - delSize; ++i)
    {
        if (std::memcmp(data + i, del, delSize) == 0)
        {
            // Delimiter found
            size_t messageLength = i; // Assuming message starts from the beginning of the buffer
            return buffer.subbuffer(0, messageLength);
        }
    }

    // Delimiter not found, return an empty Buffer
    return Buffer<BYTE>(nullptr, 0);
}

class CTimer
{
    public:
    CTimer(int id, CObject *pObj) : m_TimerID(id), m_pObject(pObj) {}
    int m_TimerID;
    CObject *m_pObject;

    // ...
};

class CObject
{
   private:
    int m_Value = 0;
    std::vector<std::unique_ptr<CTimer>> m_timerIDs;

    public:


    bool Exists(int id) const
    {
        return std::any_of(m_timerIDs.begin(), m_timerIDs.end(), [id](const auto& timer) {
            return timer->m_TimerID == id;
        });
    }

    void AddTimer(int id)
    {
        if (!Exists(id))
        {
            m_timerIDs.push_back(std::make_unique<CTimer>(id, this));
        }
    }

    void RemoveTimer(int id)
    {
        auto it = std::remove_if(m_timerIDs.begin(), m_timerIDs.end(), [id](const auto& timer) {
            return timer->m_TimerID == id;
        });
        m_timerIDs.erase(it, m_timerIDs.end());
    }
};

int main()
{

    return 0;
}