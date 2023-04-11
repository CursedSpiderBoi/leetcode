import os
import requests
import re

# Set the folder path
folder_path = "C:\CODES\leetcode\Codes"

# Get the names of all files in the folder
files = os.listdir(folder_path)

# Define a regular expression pattern to match the file extension
pattern = re.compile(r"\.[a-zA-Z0-9]+$")

# Loop over each file
for file in files:
    # Get the file name without the extension
    name = re.sub(pattern, "", file)
    
    # Combine the name with the URL string
    url = "https://leetcode.com/problems/" + "-".join(name.split())
    
    # Check if the URL is a valid webpage
    response = requests.get(url)
    
    # If the response status code is 200, write the file name to a file
    if response.status_code == 200:
        with open("valid_files.md", "a") as f:
            f.write("|" + file + "|\n")
