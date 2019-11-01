#ifndef __MEMENTO_H__
#define __MEMENTO_H__

/***
 * This is memento pattern
 * @brief memento (storing the current state of an object,  it can be restored later)
 * @time 2019/11/01
 * @authr yejy
 */

#include <string>

class CEditMemento
{
public:
    CEditMemento(std::string strStatus);
    ~CEditMemento();

    std::string GetStatus();

private:
    std::string m_strStatus;
};

class CEdit
{
public:
    CEdit(std::string strStatus);
    ~CEdit();

    CEditMemento* CreateMemento();
    void restore(CEditMemento* pMemento);

    void PrintStatus();
    void SetStatus(std::string strStatus);

private:
    std::string m_strStatus;
};
#endif // __MEMENTO_H__
