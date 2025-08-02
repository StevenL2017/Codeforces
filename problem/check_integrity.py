from pathlib import Path
import requests

HANDLE = ""


def list_files_in_directory(directory):
    res = set()
    path = Path(directory)
    for f in path.iterdir():
        if f.is_file():
            res.add(f.name.split(".")[0])
        else:
            res |= list_files_in_directory(f)
    return res


response = requests.post(url=f"https://codeforces.com/api/user.status?handle={HANDLE}")
result = response.json()["result"]
print(len(result))
passed = [x for x in result if x["verdict"] == "OK"]
print(len(passed))
problems = set([str(x["problem"]["contestId"]) + str(x["problem"]["index"]) for x in passed])
print(len(problems))

local_problems = list_files_in_directory("./archive/")
print(len(local_problems))

diff = problems - local_problems
print(diff)
