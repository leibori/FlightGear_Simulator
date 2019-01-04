//
// Created by ori on 1/4/19.
//

#ifndef SOLIDPROJECT_EX2_CACHEMANAGER_H
#define SOLIDPROJECT_EX2_CACHEMANAGER_H
template <class P, class S>

class CacheManager {

public:
    virtual bool isExist(const P &problem) const = 0;

    virtual void savePS() = 0;

    virtual S loadPS(P problem, S solution) = 0;
};
#endif //SOLIDPROJECT_EX2_CACHEMANAGER_H
