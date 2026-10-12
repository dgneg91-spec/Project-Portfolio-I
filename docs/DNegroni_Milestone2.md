Milestone 2 Development Summary
Features Added
During Milestone 2, I expanded Crypt of the Damned with several new gameplay features. The inventory system now allows the player to use Healing Potions during combat. Dungeon progression was also added so the player now moves through multiple encounters instead of fighting only one enemy. The current dungeon includes a Skeleton Warrior, Crypt Ghoul, and Bone Knight.
I also added ASCII artwork for the title screen, enemy encounters, victory screen, and death screen to improve the presentation of the console application.
Code Structure Updates
The Game class was expanded to manage dungeon progression, multiple encounters, ASCII presentation, and improved input handling. A new StartDungeon method controls the sequence of enemies and floor progression.
The Player class was expanded with functionality for using items and checking inventory size. The existing vector of Item objects is now used for actual gameplay rather than only displaying inventory contents.
Usability Improvements
One major usability improvement was replacing the previous input validation that relied on cin.fail(), clear(), and ignore() with a reusable try/catch-based method.
The updated validation handles non-numeric input, extra characters, and menu choices outside the allowed range. Clear error messages are displayed and the player is allowed to try again without disrupting the program.
Item usage was also improved so the player immediately sees how much health was restored after using a Healing Potion.
What Changed and Why
These changes were made to expand the game beyond its Milestone 1 foundation while making the program easier to understand and use.
The inventory needed meaningful functionality, the single enemy encounter needed to become an actual dungeon progression system, and the input validation needed improvement based on instructor feedback from Milestone 1.
The ASCII artwork and clearer output were added to make the console application more readable and engaging without using a graphical interface.
