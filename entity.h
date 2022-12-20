#ifndef ENTITY_H
#define ENTITY_H


#include <vector>
#include <iostream>
#include <memory>

struct Point{int x,y;}; //Temporaire, sera mis dans le "mainWindow"

class AireDeJeu;
class fauve;
class piegeAPic;
class joueur;

class Entity{
public:
    virtual ~Entity() = default;
    virtual Point position() const = 0;

};

class DynamicEntity : public Entity{

public:
    virtual ~DynamicEntity() = default;


    virtual bool estVivant() const = 0;

};

class StaticEntity : public Entity{
public:
    virtual ~StaticEntity() = default;
    virtual bool estActif() const = 0;
};








#endif // ENTITY_H







