#include <unistd.h>
#include <stdlib.h>

int main()
{
	__gid_t gid = getegid();
	__gid_t uid = geteuid();
	setresgid(gid, gid, gid);
	setresuid(uid, uid, uid);
	system("/usr/bin/env echo Exploit m");
}
