#include <map>
#include <list>
#include <string>

#include "BKNode.h"

BKNode::~BKNode()
{
    MAP_CHILDREN::iterator it = children.begin();

    while (it != children.end())
    {
        delete it->second;
        ++it;
    }

    children.clear();
}

void BKNode::add(const PAIR_S_I & _term)
{
    int d = lvstn::distance(_term.first, term.first);

    IT_CHILDREN childIt = children.find(d);

    if (childIt != children.end())
        childIt->second->add(_term);
    else
        children[d] = new BKNode (_term);
}


void BKNode::query( const STRING & word, int maxDistance, MAP_OUT & collected) const
{
    int distanceAtNode = lvstn::distance(word, term.first);

    if(distanceAtNode <= maxDistance)
    {
    	IT_MAP_OUT it = collected.begin();
        collected.insert(it, std::pair<int,int>(term.second, term.first.length()));
    }

    int score = distanceAtNode - maxDistance;

    while(score <= maxDistance + distanceAtNode)
    {
        IT_CHILDREN childIt = children.find(score);

        if (childIt != children.end())
        {
            BKNode* child = childIt->second;
            child->query(word, maxDistance, collected);
        }
        score++;
    }
}
