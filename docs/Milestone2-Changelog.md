Milestone 2 - Input Validation Improvement
Replaced the previous menu input validation that relied on std::cin.fail(), clear(), and ignore() with a reusable try/catch-based validation method.
The updated validation now:
- Rejects non-numeric input.
- Rejects input containing extra characters.
- Rejects numbers outside the available menu range.
- Displays clearer error messages.
- Allows the user to try again without interrupting program flow.
This change improves usability and addresses feedback received during Milestone 1.
