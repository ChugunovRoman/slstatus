/* See LICENSE file for copyright and license details. */
#include <stdio.h>
#include <time.h>

#include "../slstatus.h"
#include "../util.h"

const char *
datetime(const char *fmt)
{
	time_t t;

	t = time(NULL);
	if (!strftime(buf, sizeof(buf), fmt, localtime(&t))) {
		warn("strftime: Result string exceeds buffer size");
		return NULL;
	}

	return buf;
}

const char *
datetimez(const char *fmt, const int zone)
{
	time_t t, t2;
  struct tm *tm;

	t = time(NULL);

  tm = gmtime(&t);
  tm->tm_hour = tm->tm_hour + zone;
  t2 = mktime(tm);

	if (!strftime(buf, sizeof(buf), fmt, tm)) {
		warn("strftime: Result string exceeds buffer size");
		return NULL;
	}

	return buf;
}
