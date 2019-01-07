//
// Created by ori on 1/4/19.
//

#ifndef SOLIDPROJECT_EX2_CACHEMANAGER_H
#define SOLIDPROJECT_EX2_CACHEMANAGER_H
template <class P, class S>

class CacheManager {

public:
    virtual bool isExistSol(const S &sol) const = 0;
    virtual bool isExistProb(const P &pob) const =0;
    virtual void savePS(P problem, S solution) = 0;
    virtual S getSol(P problem) = 0;
    virtual void loadFromFile() = 0;
};
#endif //SOLIDPROJECT_EX2_CACHEMANAGER_H
