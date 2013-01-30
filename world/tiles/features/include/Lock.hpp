#pragma once
#include <boost/shared_ptr.hpp>
#include "ISerializable.hpp"

class Lock : public ISerializable
{
  public:
    Lock();
    Lock(const std::string& new_lock_id, const bool new_locked_val);

    virtual bool operator==(const Lock& lock);

    bool serialize(std::ostream& stream);
    bool deserialize(std::istream& stream);

    void set_lock_id(const std::string& new_lock_id);
    std::string get_lock_id() const;

    void set_locked(bool new_locked);
    bool get_locked() const;

  protected:
    std::string lock_id;
    bool locked;

  private:
    virtual ClassIdentifier internal_class_identifier() const;
};

typedef boost::shared_ptr<Lock> LockPtr;
