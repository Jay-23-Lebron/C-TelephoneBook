# C-TelephoneBook
## Project Overview
A self-learning C language contact management system, reconstructed from static array storage to dynamic singly linked list architecture.
All logic design, feature iteration, bug troubleshooting, memory security optimization and directory standardization are independently completed by me.
This portfolio project is prepared for University of Adelaide CS master application, ACS skill assessment and Australian entry-level IT job interviews.

## Core Features
### Basic CRUD Functions
- Add new contact information (name & phone number)
- Delete specified contact
- Search contacts by keyword
- Show all stored contacts
- Count total number of contacts

### Security & Optimization Features
- Dynamic singly linked list storage, no fixed capacity limit
- 11-digit phone number format validation
- Input buffer clearing to avoid program dead loop caused by illegal input
- Limit input string length to prevent buffer overflow vulnerability
- Global memory release function freeAllContacts, recycle all node memory before program exit to eliminate memory leak
- Empty linked list judgment before deletion to avoid null pointer crash
- Optimize empty search prompt text for better user experience
- All console prompts and function comments unified in English

### Code Standardization
- Modular function design, clear code layering
- Standard independent directory classification

## Standard Project Directory Structure
C-TelephoneBook/
├── data/       # Persistent storage file contact.txt
├── doc/        # Learning notes & development records
├── src/        # Core source code main.c
└── README.md   # Project introduction document

## Compile & Run Guide
Supported compilers: GCC / MinGW / Dev-C++
1. Enter src folder via terminal
2. Compile command:
```bash
gcc main.c -o telephone.exe
3.Run the program:
./telephone.exe

## Project Iteration Record
1. Initial construction (Jul 11): Initialize repository, create src/main.c, storage file contact.txt and doc development folder, build standard project directory structure.
2. Basic function development (Jul 12 - Jul 14): Complete core logic of adding contacts, searching contacts and deleting contacts based on struct array storage.
3. Global English standardization (Jul 15): Translate all Chinese console prompts to English, unify all interactive text into English.
4. Function & security supplement (Jul 18 - Jul 20): Add contact quantity statistics function, optimize empty search prompt, add phone number illegal character validation.
5. Overall bug repair (Jul 22): Troubleshoot and fix multiple implicit bugs including input dead loop, buffer overflow, null pointer crash when deleting empty list.
6. Code specification upgrade (Jul 21): Add standardized full English function comments for all modules.
7. V2.0 core architecture refactor (Jul 24 - Jul 25): Abandon static array storage, define linked list node structure, rewrite add/delete/show/search/count functions to adapt dynamic singly linked list.
8. Memory leak optimization (Jul 26): Develop freeAllContacts global function to release all linked list node memory before program exit.


