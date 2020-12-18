#include "DateTimeZone.h"

DateTimeZone::DateTimeZone() : date(), time(), zone() {}

DateTimeZone::DateTimeZone(Time timeParam, Date dateParam, TimeZone zoneParam) : time(timeParam), date(dateParam), zone(zoneParam) {}