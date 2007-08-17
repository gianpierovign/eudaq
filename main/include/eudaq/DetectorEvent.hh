#ifndef EUDAQ_INCLUDED_DetectorEvent
#define EUDAQ_INCLUDED_DetectorEvent

#include <vector>
#include "eudaq/TLUEvent.hh"
#include "eudaq/counted_ptr.hh"

namespace eudaq {

  class DetectorEvent : public Event {
    EUDAQ_DECLARE_EVENT(DetectorEvent);
  public:
    virtual void Serialize(Serializer &) const;
    explicit DetectorEvent(unsigned runnumber, unsigned eventnumber, unsigned long long timestamp) :
      Event(runnumber, eventnumber, timestamp)
      {}
//     explicit DetectorEvent(const TLUEvent & tluev) :
//       Event(tluev.GetRunNumber(), tluev.GetEventNumber(), tluev.GetTimestamp())
//       {}
    explicit DetectorEvent(Deserializer&);
    void AddEvent(counted_ptr<Event> evt);
    virtual void Print(std::ostream &) const;
    size_t NumEvents() const { return m_events.size(); }
    Event * GetEvent(size_t i) { return m_events[i].get(); }
    const Event * GetEvent(size_t i) const { return m_events[i].get(); }
  private:
    std::vector<counted_ptr<Event> > m_events;
  };

}

#endif // EUDAQ_INCLUDED_TLUEvent