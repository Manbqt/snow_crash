#include <unistd.h>
#include <sys/types.h>
#include <stdlib.h>
#include <stdio.h>

int main()
{
	gid_t gid = getegid();
	gid_t uid = geteuid();

	setresgid(gid, gid, gid);
	setresuid(uid, uid, uid);

	char *env = getenv("LOGNAME");

	asprintf(NULL, "echo %s\n", env);
	system(NULL);
}
