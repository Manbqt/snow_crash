int main(void)
{
	bool bVar1;
	long ptrace_ret;
	undefined4 uVar2;
	int iVar3;
	__uid_t uid;
	char *token;
	int iVar4;
	int in_GS_OFFSET;
	undefined local_114[256];
	int local_14;
	FILE *file;

	local_14 = *(int *)(in_GS_OFFSET + 0x14);
	bVar1 = false;
	ptrace_ret = ptrace(PTRACE_TRACEME, 0, 1, 0);
	if (ptrace_ret < 0)
	{
		puts("You should not reverse this");
		uVar2 = 1;
	}
	else
	{
		token = getenv("LD_PRELOAD");
		if (token == (char *)0x0)
		{
			iVar3 = open("/etc/ld.so.preload", 0);
			if (iVar3 < 1)
			{
				iVar3 = syscall_open("/proc/self/maps", 0);
				if (iVar3 == -1)
				{
					fwrite("/proc/self/maps is unaccessible, probably a LD_PRELOAD attempt exit..\n", 1, 0x46,
						   stderr);
					uVar2 = 1;
				}
				else
				{
					do
					{
						do
						{
							while (true)
							{
								iVar4 = syscall_gets(local_114, 0x100, iVar3);
								if (iVar4 == 0)
									goto LAB_08048ead;
								iVar4 = isLib(local_114, &DAT_08049063);
								if (iVar4 == 0)
									break;
								bVar1 = true;
							}
						} while (!bVar1);
						iVar4 = isLib(local_114, &DAT_08049068);
						if (iVar4 != 0)
						{
							fwrite("Check flag.Here is your token : ", 1, 0x20, stdout);
							uid = getuid();
							file = stdout;
							if (uid == 3006)
							{
								token = (char *)ft_des("H8B8h_20B4J43><8>\\ED<;j@3");
								fputs(token, file);
							}
							else if (uid < 3007)
							{
								if (uid == 0xbba)
								{
									token = (char *)ft_des("<>B16\\AD<C6,G_<1>^7ci>l4B");
									fputs(token, file);
								}
								else if (uid < 3003)
								{
									if (uid == 3000)
									{
										token = (char *)ft_des("I`fA>_88eEd:=`85h0D8HE>,D");
										fputs(token, file);
									}
									else if (uid < 3001)
									{
										if (uid == 0)
										{
											fwrite("You are root are you that dumb ?\n", 1, 0x21, stdout);
										}
										else
										{
										LAB_08048e06:
											fwrite("\nNope there is no token here for you sorry. Try again :)", 1, 0x38,
												   stdout);
										}
									}
									else
									{
										token = (char *)ft_des("7`4Ci4=^d=J,?>i;6,7d416,7");
										fputs(token, file);
									}
								}
								else if (uid == 3004)
								{
									token = (char *)ft_des("?4d@:,C>8C60G>8:h:Gb4?l,A");
									fputs(token, file);
								}
								else if (uid < 3005)
								{
									token = (char *)ft_des("B8b:6,3fj7:,;bh>D@>8i:6@D");
									fputs(token, file);
								}
								else
								{
									token = (char *)ft_des("G8H.6,=4k5J0<cd/D@>>B:>:4");
									fputs(token, file);
								}
							}
							else if (uid == 3010)
							{
								token = (char *)ft_des("74H9D^3ed7k05445J0E4e;Da4");
								fputs(token, file);
							}
							else if (uid < 3011)
							{
								if (uid == 0xbc0)
								{
									token = (char *)ft_des("bci`mC{)jxkn<\"uD~6%g7FK`7");
									fputs(token, file);
								}
								else if (uid < 3009)
								{
									token = (char *)ft_des("78H:J4<4<9i_I4k0J^5>B1j`9");
									fputs(token, file);
								}
								else
								{
									token = (char *)ft_des("Dc6m~;}f8Cj#xFkel;#&ycfbK");
									fputs(token, file);
								}
							}
							else if (uid == 3012)
							{
								token = (char *)ft_des("8_Dw\"4#?+3i]q&;p6 gtw88EC");
								fputs(token, file);
							}
							else if (uid < 3012)
							{
								token = (char *)ft_des("70hCi,E44Df[A4B/J@3f<=:`D");
								fputs(token, file);
							}
							else if (uid == 3013)
							{
								token = (char *)ft_des("boe]!ai0FB@.:|L6l@A?>qJ}I");
								fputs(token, file);
							}
							else
							{
								if (uid != 3014)
									goto LAB_08048e06;
								token = (char *)ft_des("g <t61:|4_|!@IF.-62FH&G~DCK/Ekrvvdwz?v|");
								fputs(token, file);
							}
							fputc(10, stdout);
							goto LAB_08048ead;
						}
						iVar4 = afterSubstr(local_114, "00000000 00:00 0");
					} while (iVar4 != 0);
					fwrite("LD_PRELOAD detected through memory maps exit ..\n", 1, 0x30, stderr);
				LAB_08048ead:
					uVar2 = 0;
				}
			}
			else
			{
				fwrite("Injection Linked lib detected exit..\n", 1, 0x25, stderr);
				uVar2 = 1;
			}
		}
		else
		{
			fwrite("Injection Linked lib detected exit..\n", 1, 0x25, stderr);
			uVar2 = 1;
		}
	}
	if (local_14 == *(int *)(in_GS_OFFSET + 0x14))
	{
		return uVar2;
	}
	/* WARNING: Subroutine does not return */
	__stack_chk_fail();
}
