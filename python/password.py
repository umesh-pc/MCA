import re

def is_valid_password(password):
    
    if len(password) < 6 or len(password) > 16:
        return False, "Password must be between 6 and 16 characters."
    
    
    if not re.search(r"[a-z]", password):
        return False, "Password must contain at least one lowercase letter."
    
    
    if not re.search(r"[A-Z]", password):
        return False, "Password must contain at least one uppercase letter."
    
    
    if not re.search(r"[0-9]", password):
        return False, "Password must contain at least one digit."
    
   
    if not re.search(r"[$#@]", password):
        return False, "Password must contain at least one special character ($, #, or @)."
    
    return True, "Password is valid."


password = input("Enter your password: ")
valid, message = is_valid_password(password)
print(message)
