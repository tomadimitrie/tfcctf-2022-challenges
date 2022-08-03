import dataclasses
import errno
import os
import random

FLAG = os.environ.get("FLAG")

if not FLAG:
    print("If you're running this locally, please create a fake flag env variable.")
    print("If you're seeing this on the remote server, please contact the admins.")
    exit(errno.ENOENT)


@dataclasses.dataclass
class Message:
    message: str

    def __str__(self):
        return self.message

    __repr__ = __str__


MESSAGES = [
    Message("Thank you for using our service."),
    Message("Here is your pattern:"),
    Message("Until next time!")
]

pattern = input("pattern> ")
count = int(input("count> "))

final_pattern = pattern * count
print(f"{{message}} {final_pattern}".format(message=random.choice(MESSAGES)))
