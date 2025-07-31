#ifndef BUILDER_H
#define BUILDER_H

template<class T>
class Builder {
public:
    virtual ~Builder() = default;

protected:
    virtual T build() = 0;
};

#endif //BUILDER_H
