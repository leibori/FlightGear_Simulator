//
// Created by ori on 1/4/19.
//

#ifndef SOLIDPROJECT_EX2_CACHEMANAGER_H
#define SOLIDPROJECT_EX2_CACHEMANAGER_H
template <class question, class Answer>

class CacheManager {

public:
    virtual bool isExist(const Question &item) const = 0;

    virtual Answer getAnswer(Question question) = 0;

    virtual bool addAnswerAndQuestion(Question question, Answer answer) = 0;
};
#endif //SOLIDPROJECT_EX2_CACHEMANAGER_H
