# Milestone 3 - Crypt of the Damned

## Features Added

During Milestone 3, I continued expanding Crypt of the Damned with several gameplay improvements and fixes.

### Player State Reset
I added a reset system so starting a new game now correctly resets the player's health, gold, inventory, defending state, and other gameplay values. This prevents values from a previous playthrough from carrying into a new game.

### Healing Potion Balance
Healing Potions now count as the player's turn during combat. After successfully using a potion, the enemy is allowed to take its turn. This makes item use more balanced and prevents healing from becoming a free action.

### Improved Defend System
The Defend option was expanded to make it more useful and strategic.

Defend now has two possible outcomes:

- There is a 25% chance of performing a Perfect Block.
- A Perfect Block completely prevents the enemy's attack and allows the player to immediately counterattack for double damage.
- If the Perfect Block does not occur, the player still blocks half of the incoming damage.

Combat feedback was also improved so the program clearly displays how much damage was blocked and how much damage the player actually received.

### Unique Enemy Combat Abilities
The enemy system was expanded so enemies now have different combat behavior instead of only having different health and attack values.

- Skeleton Warrior uses normal attacks.
- Crypt Ghoul has a chance to use Savage Claw for increased damage.
- Bone Knight has a chance to use Crushing Blow for increased damage.

This makes each dungeon encounter feel more distinct and gives the player more reason to think about when to attack, defend, or use an item.

---

## System Design Updates

### Meaningful Pointer Usage
The Game class now uses an Enemy pointer named `currentEnemy`.

The pointer tracks which Enemy object from the dungeon's enemy vector is currently active in combat. Instead of copying the current enemy into another object, the pointer directly references the existing Enemy object.

This allows the combat system to modify the correct enemy's health and other data while also satisfying the project's pointer usage requirement in a meaningful way.

The pointer is initialized to `nullptr`, assigned to the current enemy before combat begins, and reset to `nullptr` when it is no longer needed.

### Enemy Combat Behavior
Enemy attack behavior was moved into the Enemy class through a new attack damage function.

The Enemy class now determines whether the enemy performs a normal attack or one of its special attacks. This keeps enemy-specific behavior inside the Enemy class instead of adding more enemy logic directly into the main combat loop.

---

## Refactoring Improvements

One of the major goals for Milestone 3 was improving code organization instead of only adding more features.

The original `StartCombat()` function was handling too many responsibilities at once. It displayed combat information, displayed the menu, processed player actions, handled item use, processed enemy attacks, and handled the end of combat.

I refactored the combat system into several smaller functions.

### DisplayCombatStatus()
This function displays the player's health and the current enemy's health.

### DisplayCombatMenu()
This function displays all combat menu choices.

### HandlePlayerAction()
This function processes the action selected by the player and determines whether the enemy should receive a turn.

### HandleItemUse()
This function handles inventory selection and item use during combat.

### HandleDefend()
This function handles the Defend action, including the Perfect Block chance, normal blocking, and counterattacks.

### ProcessEnemyTurn()
This function handles the enemy's attack, calculates the actual amount of damage taken, and displays clearer damage information.

### ProcessCombatResult()
This function handles what happens after combat ends, including gold rewards, victory messages, and player death.

The refactored `StartCombat()` function is now mainly responsible for controlling the combat loop and calling these smaller functions.

---

## What Changed and Why

The main focus of Milestone 3 was improving both the gameplay and the organization of the existing code.

The player reset system was added because health, gold, and inventory values were carrying over into new games. Resetting the player at the beginning of each new game fixes this issue and makes each playthrough start correctly.

Healing Potions were changed because using a potion previously allowed the player to heal without the enemy receiving a turn. This made combat easier than intended. Potions now correctly use the player's turn.

The Defend option was improved because the original version only reduced incoming damage and did not provide enough benefit compared to attacking. The Perfect Block and counterattack system gives Defend a more meaningful risk and reward.

Enemy-specific attacks were added because the enemies previously played almost the same way even though they had different statistics. Giving enemies unique attacks makes combat less repetitive and gives each enemy more personality.

The combat system was refactored because `StartCombat()` had become too large and was responsible for too many different tasks. Breaking the function into smaller responsibilities makes the code easier to read, test, debug, and expand later.

The `currentEnemy` pointer was added so the combat system can directly work with the Enemy object currently being fought. This provides meaningful pointer usage while also improving how the current enemy is tracked throughout combat.

Overall, Milestone 3 focused on making Crypt of the Damned more balanced, more organized, and easier to continue expanding during Milestone 4.
