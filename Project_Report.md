# Local Training Workshop Registration System

**Student:** Josiel Pantin  
**Institution:** CEMJC  
**Course:** Fundamentals of Programming  
**Instructor:** ______________________________  
**Date:** 24 November 2026

## 1. Project Proposal

### Project title
Local Training Workshop Registration System

### Intended users
The intended users are staff members or volunteers who organize local training workshops in Belize. Participants provide their names and phone numbers and select the workshop they want to attend.

### Local relevance and problem
Belize has organizations that provide workforce and professional-development training. For example, the Belize Training and Employment Centre (BTEC), a unit of BELTRAIDE, lists job-preparedness and professional-development training. Its professional-development offerings include short workshops and a computer-skills series (Belize Training and Employment Centre, n.d.; BELTRAIDE, n.d.). This supports the local relevance of a workshop-registration application.

This project uses a small training organization as its example user. It does not claim that BTEC or another named organization currently uses paper records or has a registration problem. The proposed system is a student project that demonstrates how a small organization could organize participant records.

### Proposed solution
The proposed solution is a menu-driven C++ console application. It allows staff to register participants, display the participant list, search by name, and view a summary. It checks entries so that empty names, invalid phone numbers, and menu choices outside the allowed range are rejected.

### Expected benefits
- Keeps participant information together during a program session.
- Makes it easier to find a participant by name.
- Automatically assigns a registration ID.
- Shows the total number of registrations.
- Shows how many participants selected each workshop.

## 2. Scope and Limitations

The application offers four sample workshops: Computer Basics, Microsoft Office Training, Digital Marketing, and Basic Computer Programming. It can hold up to 100 participants in one program run. It does not collect payments, send confirmation messages, or save information after the program closes. The workshop names and capacity can be changed in the source code.

## 3. Functional Requirements

1. The system shall allow staff to register a participant by entering a name, phone number, and workshop choice.
2. The system shall reject an empty participant name.
3. The system shall accept a phone number only when it contains 7 to 15 digits.
4. The system shall assign each successful registration a unique ID, starting at 1001.
5. The system shall display all registered participants.
6. The system shall allow staff to search participant names without case sensitivity.
7. The system shall show a message when no matching participant is found.
8. The system shall display the total number of participants, remaining spaces, and registrations for each workshop.
9. The system shall allow the user to return to the menu and repeat tasks until Exit is selected.
10. The system shall reject invalid menu and workshop choices and ask the user to try again.

## 4. Inputs, Processing, and Outputs

### Inputs
- Menu choice (1 to 5)
- Participant name
- Phone number (7 to 15 digits)
- Workshop choice (1 to 4)
- Name text for searching

### Processing
- Check that required text is not empty.
- Check that numeric choices are within the allowed range.
- Check that the phone number contains only digits and has an allowed length.
- Create a participant object and assign the next registration ID.
- Store participant objects in an array.
- Compare names in lowercase form when searching.
- Count registrations for each workshop.

### Outputs
- Registration success message and ID
- Participant details
- Search result or not-found message
- Registration summary
- Error messages for invalid input

## 5. Assumptions and Constraints

- The organization has a computer with a C++ compiler.
- Staff members enter the information.
- The sample workshop list is suitable for demonstrating the system.
- Phone numbers are entered as digits only.
- The program supports a maximum of 100 participants in one run.
- Information is stored in memory and is lost when the program closes.
- The program is a demonstration and uses fictional participant information during testing.

## 6. Algorithm / Pseudocode

START  
Create the registration system.  
Set participant count to zero and next ID to 1001.  
REPEAT  
&nbsp;&nbsp;Display the main menu.  
&nbsp;&nbsp;Get and validate the menu choice.  
&nbsp;&nbsp;IF choice is 1  
&nbsp;&nbsp;&nbsp;&nbsp;Check that the array has space.  
&nbsp;&nbsp;&nbsp;&nbsp;Get a non-empty name.  
&nbsp;&nbsp;&nbsp;&nbsp;Get a valid phone number.  
&nbsp;&nbsp;&nbsp;&nbsp;Display workshops and get a valid choice.  
&nbsp;&nbsp;&nbsp;&nbsp;Create and store the participant.  
&nbsp;&nbsp;&nbsp;&nbsp;Display the registration ID.  
&nbsp;&nbsp;ELSE IF choice is 2  
&nbsp;&nbsp;&nbsp;&nbsp;Display all participants or an empty-list message.  
&nbsp;&nbsp;ELSE IF choice is 3  
&nbsp;&nbsp;&nbsp;&nbsp;Search names without case sensitivity.  
&nbsp;&nbsp;&nbsp;&nbsp;Display matching participants or a not-found message.  
&nbsp;&nbsp;ELSE IF choice is 4  
&nbsp;&nbsp;&nbsp;&nbsp;Display total registrations, spaces, and workshop counts.  
&nbsp;&nbsp;ELSE  
&nbsp;&nbsp;&nbsp;&nbsp;Display the exit message.  
UNTIL choice is 5  
END

## 7. Program Design

The program is divided into three main parts:
- `Participant` stores one participant's ID, name, phone number, and workshop. Its data is private and is accessed through member functions.
- `RegistrationSystem` stores up to 100 participants in a `std::array` and controls registration, display, searching, summaries, and the menu.
- `main.cpp` creates the system and starts it.

The program uses functions with separate responsibilities, an array, strings, decisions, loops, input validation, and classes. There are no global variables. The `std::array` container is suitable for this version because the project uses a fixed capacity of 100 records (cppreference.com, n.d.-a).

## 8. Build and Test Results

The program was compiled using:

```bash
g++ -std=c++11 -Wall -Wextra -pedantic main.cpp participant.cpp registration.cpp -o workshop
```

**Build result:** The program compiled successfully. No compiler warnings were printed.  
**Test result:** 13 of 13 console tests passed in the local test run on 24 November 2026. The full test cases, inputs, expected results, actual results, and pass statuses are in `Testing_Results.md`.

The test run covered empty collections, invalid menu entries, empty names, invalid phone numbers, invalid workshop choices, sequential registration IDs, case-insensitive search, blank search text, summary counts, and the 100-participant capacity limit. The tests were run in the available local environment. They are not screenshots from the student's own computer; the student should repeat the tests in their IDE and capture any evidence required by the lecturer.

## 9. Debugging Record

The final build completed without compiler errors or warnings. All 13 tests passed, including the test for a blank search phrase. The search function contains a validation loop that asks again when the search phrase is empty. No failing defect was observed in this final test run, so it would be inaccurate to claim that a specific defect was reproduced and fixed.

The assignment asks for at least one defect and its correction. To complete that part honestly, the student must record a real defect if one appears during their own testing: include the exact input, the incorrect result, the cause, the code change, and the successful retest. Do not submit an invented debugging story.

## 10. Limitations and Future Improvements

The current program does not save records after closing. A future version could save participant details in a file or database. It could also include workshop dates, a workshop capacity for each course, registration cancellation, and printed confirmation slips.

## 11. Individual Reflection — Draft

This project helped me practice organizing a C++ program using classes, functions, arrays, strings, decisions, and loops. The program also showed why input validation is important because users may enter information in the wrong format. The participant information is kept in a class, while the registration tasks are handled by a separate system class. I tested the program with normal entries, invalid entries, searches, summaries, and the maximum number of participants. The local test run passed all 13 test cases. One limitation is that the program does not save registrations after it closes. A future improvement would be to save the records in a file or database.

**Before submission, revise this reflection to describe your own work, the challenge you personally experienced, and what happened when you repeated the tests on your computer.**

## 12. AI Use and Source Declaration

AI tool used: ChatGPT by OpenAI.  
Purpose: Assistance with planning the program structure, drafting example C++ code, preparing documentation, and suggesting test cases.  
Student verification: The student must review and understand the code, compile it, repeat the tests, revise the draft where needed, and be able to explain the functions.  

## References

Belize Training and Employment Centre. (n.d.). *Belize Training & Employment Centre (BTEC).* BELTRAIDE. https://beltraide.bz/btec/

BELTRAIDE. (n.d.). *Professional development.* https://beltraide.bz/professional-development/

cppreference.com. (n.d.-a). *std::array.* https://www.cppreference.com/w/cpp/container/array

cppreference.com. (n.d.-b). *std::stoi, std::stol, std::stoll.* https://en.cppreference.com/w/cpp/string/basic_string/stol
