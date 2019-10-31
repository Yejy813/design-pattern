#ifndef __MEDIATOR_H__
#define __MEDIATOR_H__

/***
 * This is mediator pattern
 * @brief mediator (encapsulates how a set of objects interact)
 * @time 2019/10/31
 * @authr yejy
 */

#include <string>

class CUser;
class CChatRoomMediator
{
public:
    virtual ~CChatRoomMediator();
    virtual void ShowMessage(CUser* user, std::string strMessge) = 0;

protected:
    CChatRoomMediator();
};

class CChatRoom : public CChatRoomMediator
{
public:
    ~CChatRoom();
    CChatRoom();
    void ShowMessage(CUser* user, std::string strMessge);
};


class CUser
{
public:
    virtual ~CUser();
    virtual void SendMessage(std::string strMessge) = 0;
    virtual std::string GetName() = 0;

protected:
    CUser(std::string strName, CChatRoomMediator* pChat);

public:
    std::string m_strName;
    CChatRoomMediator* m_pChat;
};

class CUserJohn : public CUser
{
public:
    ~CUserJohn();
    CUserJohn(std::string strName, CChatRoomMediator* pChat);
    void SendMessage(std::string strMessge);
    std::string GetName();
};

class CUserJame : public CUser
{
public:
    ~CUserJame();
    CUserJame(std::string strName, CChatRoomMediator* pChat);
    void SendMessage(std::string strMessge);
    std::string GetName();
};

#endif // __MEDIATOR_H__
