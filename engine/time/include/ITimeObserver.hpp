#pragma once
#include <string>
#include <boost/shared_ptr.hpp>
#include "common.hpp"

namespace boost
{
  namespace serialization
  {
    class access;
  }
}

class ITimeObserver
{
  public:
    ITimeObserver();
    virtual ~ITimeObserver() {};
    
    virtual void notify(const ulonglong minutes_elapsed) = 0;
    virtual std::string get_id() const;

  protected:
    virtual std::string generate_id();
    virtual void update_minutes_elapsed(const int minutes_elapsed);

    ulonglong minutes_elapsed;
    std::string id;
    
  private:
    friend class boost::serialization::access;
    
    template<typename Archive>
    void serialize(Archive& ar, const unsigned int version)
    {
      ar & minutes_elapsed & id;
    }
};

typedef boost::shared_ptr<ITimeObserver> ITimeObserverPtr;
