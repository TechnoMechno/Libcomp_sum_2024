import subprocess

result = subprocess.run(['./test'], text=True, capture_output=True)
print(result.stdout)


