import os

folder = "level"

for folder_index in range(0,15):
	try: 
		mandatory_folder = folder + '{:02d}'.format(folder_index);
		os.mkdir(mandatory_folder)

		resource_folder = os.path.join(mandatory_folder, "resources")
		os.mkdir(resource_folder)

		flag_file_path = os.path.join(mandatory_folder, "flag")
		os.mknod(flag_file_path)

		readme_file_path = os.path.join(mandatory_folder, "README.md")
		os.mknod(readme_file_path)
	except FileExistsError as e:
		print(f'An error occured: {e}')

