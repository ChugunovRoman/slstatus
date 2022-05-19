/* See LICENSE file for copyright and license details. */
#include <stdio.h>
#include <string.h>

#include "../util.h"

unsigned long int wait = 0;
char cached_buf[1024];

const char *
run_command(const char *cmd, const unsigned int interval)
{
  wait += 1000;

  if (strlen(cached_buf) > 0 && wait % interval != 0) {
    return cached_buf;
  }

	char *p;
	FILE *fp;

	if (!(fp = popen(cmd, "r"))) {
		warn("popen '%s':", cmd);
		return NULL;
	}
	p = fgets(buf, sizeof(buf) - 1, fp);
	if (pclose(fp) < 0) {
		warn("pclose '%s':", cmd);
		return NULL;
	}
	if (!p) {
		return NULL;
	}
	if ((p = strrchr(buf, '\n'))) {
		p[0] = '\0';
	}

  strcpy(cached_buf, buf);

	return buf[0] ? buf : NULL;
}
