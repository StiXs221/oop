#ifndef GAMEOBJ_H
#define GAMEOBJ_H
#include "globalconst.h"
#include "PublicObj.h"
class IMediator;
class GameField;

class GameObj : public PublicObj
{
friend GameField;
protected:
    static int Count;
    int x_;
    int y_;
    GameField* field_;
    int character;
public:
    int getX();
    int getY();
    virtual void setPosition(GameField* field, int x, int y);
    GameObj();
    virtual void setMediator(IMediator*);
    virtual int getSpace();
    virtual bool isHero();
    virtual bool isNeutral();
    virtual void update() {}
    static int getCount();
    int getAnimation();
    virtual ~GameObj() {}
};

#endif // GAMEOBJ_H
