def caesar_encrypt(text, shift):
    encrypted_text = ""
    for char in text:
        if char.isalpha():
            shift_amount = shift % 26
            if char.islower():
                start = ord('a')
                encrypted_char = chr(start + (ord(char) - start + shift_amount) % 26)
            elif char.isupper():
                start = ord('A')
                encrypted_char = chr(start + (ord(char) - start + shift_amount) % 26)
            encrypted_text += encrypted_char
        else:
            encrypted_text += char
    return encrypted_text

def main():
    plain_text = input("Enter the plain text: ")
    shift = int(input("Enter the shift value: "))
    
    cipher_text = caesar_encrypt(plain_text, shift)
    
    print(f"Plain text: {plain_text}")
    print(f"Cipher text: {cipher_text}")

if __name__ == "__main__":
    main()
