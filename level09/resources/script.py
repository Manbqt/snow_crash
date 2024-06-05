import sys
from textwrap import wrap

with open(sys.argv[1]) as file:
	data_hex = file.read().encode("hex")

	# Used to split the string into two-characters string
	data_split = wrap(data_hex, 2)

	converted_hex = ""

	for i, c in enumerate(data_split):
		converted = int(c, 16) - i
		if converted > 0:
			converted_hex += '{:02x}'.format(converted)
	print("Token: ", converted_hex.decode("hex"))
