# Testing Results — Local Training Workshop Registration System

**Build command:** `g++ -std=c++11 -Wall -Wextra -pedantic main.cpp participant.cpp registration.cpp -o workshop`

**Build result:** Successful with no compiler warnings.

| Test | Input / action | Expected result | Observed result |
|---|---|---|---|
| Register | Enter Ana Lopez, phone `6001234`, and workshop 2 | Create participant ID 1001 | ID 1001 was displayed |
| Invalid phone | Enter `abc`, then `6001234` | Reject letters and accept valid digits | Invalid phone was rejected; valid phone accepted |
| Display | Select option 2 after registration | Show participant details | ID, name, phone, and workshop displayed |
| Search by name | Select search, then name option, enter `Ana` | Find matching participant | Ana Lopez was displayed |
| Summary | Select option 4 after registration | Show total and workshop counts | Total 1 and Microsoft Office Training count 1 displayed |
| Exit | Select option 5 | End the program | Thank-you message displayed and program ended |

These checks were run in the available local C++ environment. Repeat them in your own IDE and capture your own screenshots if required by your instructor.

## Debugging note
During the first compile of this shorter version, the compiler identified that `searchMenu()` was marked `const` even though it called input functions. I removed `const` from its declaration in `registration.h` and its definition in `registration.cpp`. I compiled again and reran the registration, search, display, and summary checks successfully.
