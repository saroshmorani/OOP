#include <iostream>
#include <memory>
#include <typeinfo>
#include <typeindex>
#include <stdexcept>

class BadTypeException : public std::exception {
public:
    const char* what() const noexcept override {
        return "BadTypeException: Incorrect type access.";
    }
};

class Placeholder {
public:
    virtual ~Placeholder() = default;
    virtual std::type_index type() const = 0;
    virtual std::unique_ptr<Placeholder> clone() const = 0;
};

template<typename T>
class Holder : public Placeholder {
public:
    T data;

    Holder(const T& val) : data(val) {}

    std::type_index type() const override {
        return typeid(T);
    }

    std::unique_ptr<Placeholder> clone() const override {
        return std::make_unique<Holder<T>>(data);
    }
};

class TypeSafeContainer {
private:
    std::unique_ptr<Placeholder> content;

public:
    TypeSafeContainer() = default;

    TypeSafeContainer(const TypeSafeContainer& other) {
        if (other.content)
            content = other.content->clone();
    }

    TypeSafeContainer& operator=(const TypeSafeContainer& other) {
        if (this != &other) {
            content = other.content ? other.content->clone() : nullptr;
        }
        return *this;
    }

    template<typename T>
    void store(const T& value) {
        content = std::make_unique<Holder<T>>(value);
    }

    template<typename T>
    T get() const {
        if (!content || content->type() != typeid(T)) {
            throw BadTypeException();
        }

        return static_cast<Holder<T>*>(content.get())->data;
    }
};

int main() {
    TypeSafeContainer container;

    container.store<std::string>("Hello TypeSafe World!");
    try {
        cout << container.get<std::string>() << "\n";
        cout << container.get<int>() << "\n";
    } catch (const BadTypeException& e) {
        cout<< e.what() << "\n";
    }

    return 0;
}

