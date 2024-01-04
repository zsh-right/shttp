#ifndef YAZI_UTILITY_SINGLETON_H
#define YAZI_UTILITY_SINGLETON_H

#include <mutex>
#include <memory>

namespace yazi {
namespace utility {

enum class SingletonType {
    HUNGRY,
    LAZY,
    AUTO
};

template<typename T>
class Singleton_Interface;

template<typename T>
class Lazy_Singleton;

template<typename T>
class Hungry_Singleton;


template <typename T, SingletonType type = SingletonType::LAZY>
class Singleton
{
public:
    static T * instance()
    {
        if (type == SingletonType::LAZY) {
            return Lazy_Singleton<T>::instance();
        } else if (type == SingletonType::HUNGRY) {
            return Hungry_Singleton<T>::instance();
        } else if (type == SingletonType::AUTO) {
        }
        return nullptr;
    }

private:
    Singleton() = default;
    Singleton(const Singleton<T> &) = delete;
    Singleton<T> & operator = (const Singleton<T> &) = delete;
    ~Singleton() = default;
};

template <typename T>
class Hungry_Singleton
{
public:
    static T* instance()
    {
        return instance_;
    }

private:
    Hungry_Singleton() = default;
    Hungry_Singleton(const Hungry_Singleton &) = delete;
    Hungry_Singleton & operator = (const Hungry_Singleton &) = delete;
    ~Hungry_Singleton() = default;
    static T* instance_;
};

template <typename T>
T* Hungry_Singleton<T>::instance_ = new T();

template <typename T>
class Lazy_Singleton
{
public:
    static T* instance()
    {
        if (instance_)
            return instance_;

        std::lock_guard<std::mutex> lock(mutex_);
        if (instance_)
            return instance_;

        instance_ = new T();
        return instance_;
    }

protected:
    Lazy_Singleton() = default;

private:
    Lazy_Singleton(const Lazy_Singleton &) = delete;
    Lazy_Singleton & operator = (const Lazy_Singleton &) = delete;
    ~Lazy_Singleton() = default;
    static T* instance_;
    static std::mutex mutex_;
};

template<typename T>
T* Lazy_Singleton<T>::instance_ = nullptr;

template<typename T>
std::mutex Lazy_Singleton<T>::mutex_;

template <typename T>
class Auto_Singleton
{
public:
    static T* instance()
    {
        if (instance_)
            return instance_.get();

        std::lock_guard<std::mutex> lock(mutex_);
        if (instance_)
            return instance_.get();

        instance_ = std::shared_ptr<T>(new T());
        return instance_.get();
    }

private:
    Auto_Singleton() = default;
    Auto_Singleton(const Auto_Singleton &) = delete;
    Auto_Singleton & operator = (const Auto_Singleton &) = delete;
    ~Auto_Singleton() = default;
    static std::shared_ptr<T> instance_;
    static std::mutex mutex_;
};

template <typename T>
std::shared_ptr<T> Auto_Singleton<T>::instance_ = nullptr;

}}

#endif
// vim: set et ts=4 sts=4 sw=4:
