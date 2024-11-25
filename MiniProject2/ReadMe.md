# cryptoMagic

## What is cryptoMagic?

cryptoMagic is a command line utility designed to encrypt and decrypt `.txt` files to and from `.crp` files. It employs the CRP encryption protocol, which follows these steps:

---

1. Converts ASCII characters to their numerical values.
2. Subtracts 16 from these values.
3. If the resulting value is below 32, it further subtracts 32 and adds 144.
4. The final values are then written into a `.crp` file in hexadecimal format.

## our goal

Our goal with **cryptoMagic** is to provide a user-friendly, efficient, and secure tool for encrypting and decrypting files. We aim to:

1. **Enhance Data Security:** Ensure that sensitive information is protected through robust encryption protocols.
2. **Simplify Encryption:** Make the encryption and decryption processes straightforward and accessible, even for users who may not be tech-savvy.
3. **Maintain Integrity:** Guarantee the accuracy and reliability of the data during the encryption and decryption processes.
4. **Improve Flexibility:** Offer a versatile tool that can handle various file types and scenarios, making it useful for a wide range of applications.
5. **Ensure Accessibility:** Create a command line utility that is easy to use and integrate into existing workflows.

By achieving these goals, **cryptoMagic** will empower users to confidently manage their sensitive data with ease and security.

## Why cryptoMagic?

The name **cryptoMagic** perfectly captures the essence of what the utility does. "Crypto" refers to the encryption and decryption processes, safeguarding the information. "Magic" adds a touch of intrigue and simplicity, suggesting that it transforms your files with just a few commands—almost like magic! ✨🔐

It's all about making the complex process of encryption feel seamless and intuitive. Plus, who doesn't love a bit of magic in their tech tools? 💫

## **How You Can Help Us Achieve Our Goal**

We believe in the power of collaboration and would love your support in making **cryptoMagic** the best it can be. Here are a few ways you can contribute:

1. **Feedback:** Share your thoughts and experiences using cryptoMagic. Your feedback helps us identify areas for improvement and new features that would make the tool even more useful.
2. **Testing:** Participate in beta testing new features and updates. This helps us ensure everything works smoothly and meets users' needs.
3. **Documentation:** Help us create clear and comprehensive documentation, including user guides, tutorials, and FAQs. This makes it easier for others to get the most out of cryptoMagic.
4. **Spread the Word:** Tell others about cryptoMagic and how it can help them secure their data. The more people know about it, the more we can refine and grow the tool.
5. **Contribute Code:** If you have coding skills, consider contributing to the development of cryptoMagic. Whether it's bug fixes, new features, or optimization, your code can make a big difference.

Together, we can make **cryptoMagic** a reliable and user-friendly encryption tool for everyone. 🚀🔐✨

Ready to join us on this journey?

## How to Use cryptoMagic

**cryptoMagic** is a command-line utility that allows you to encrypt and decrypt files using the CRP encryption protocol. Here are the steps to use it:

1. **Command-Line Switches:**
   * `-E` for Encrypt
   * `-D` for Decrypt
   * If neither switch is specified, encryption is assumed by default.
2. **Input File Argument:**
   * The utility requires the name of the ASCII input file to be encrypted or decrypted as an argument.

### Examples:

* **Encrypt a file:**

  ```powershell
  cryptoMagic -E myFile.txt
  ```

  This command will encrypt the contents of `myFile.txt` and produce an encrypted file called `myFile.crp`.
* **Encrypt a file without specifying the switch:**

  ```powershell
  cryptoMagic myFile.txt
  ```

  This command will also encrypt `myFile.txt` and produce `myFile.crp`.
* **Decrypt a file:**

  ```powershell
  cryptoMagic -D myFile.crp
  ```

  This command will decrypt the contents of `myFile.crp` and produce a decrypted file called `myFile.txt`

By following these instructions, you can easily use cryptoMagic to secure and access your files. If you have any questions or need further assistance, feel free to ask! 😊🔐✨

## Installation Instructions:

* **Download the Source Code:**
  * Obtain the folder containing the source code for  **cryptoMagic** .
* **Compile the Source Code:**
  * Use `gcc` to compile the code. Open your terminal and navigate to the directory where the source code is located.
  * Run the following command:

    ```powershell
    gcc main.c -o cryptoMagic
    ```

    This will compile the source code and create an executable named `cryptoMagic`.

Once compiled, you can start using cryptoMagic to encrypt and decrypt your files! If you encounter any issues during installation, feel free to reach out for support. 😊🔐✨


## Troubleshooting:

- Ensure your input files are in the correct format.
- If encryption or decryption fails, check for any special characters or unsupported formats in the input file.

## FAQs:

- What file types can be encrypted/decrypted? Any ASCII text files can be encrypted/decrypted using cryptoMagic.
- Can I encrypt/decrypt files with no extensions? Yes, cryptoMagic handles files with or without extensions seamlessly.

## Contact Information:
For support or questions, please contact us at [caoe@uoguelph.ca](caoe@uoguelph.ca) or visit our [discord server](https://discord.gg/GBY2Hbb2).