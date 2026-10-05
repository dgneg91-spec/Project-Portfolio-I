# Instructions

Update this document where indicated [look for the brackets!]. Replace text inside the brackets with your own information. For example: Course Name should be the name of this course, and not the generic words "Course Name".

<br>

## [Project and Portfolio I: Computer Science]

- **[ David Negroni ]**
- **[ October 4 2026 ]**

This paper addresses some of the topic matter covered in research and activity this week. Be sure to include reference links below to the research and information you used to complete this assignment.

## Topic: Terminal

Professional developers use Terminal daily. It's essential to understand some fundamental commands to use the application.

Update the information below to demonstrate your knowledge on this topic.

**1. Using Terminal, there are essential commands to know.**

List the correct Terminal commands to do the actions listed below. Replace **CMD** with the correct command sequence. You can keep or enhance the brief description.

**The last bullet provides an example**.

- [ clear ]: Clear the Screen
- [ pwd ]: Print the "Working Directory"
- [ ls ]: List files and folders
- [ ls -a ]: List files and folders, including invisible files
- [ ls -lh]: List all files and folders, in human readable form
- [ cd]: Change directory
- [ cd / ]: Change directory, go to root directory
- [ cd ~ ]: Change directory and go to user home directory
- [ cd ..]: Change directory, go up one folder level
- [ cd../.. ]: Change directory, go up two folder levels
- [ cd ~/Desktop]: Change directory to my desktop!

**2. Using Terminal...**

**Folder Drop:** Try typing "cd" followed by a space, and then drag a folder into terminal and press return. Test this out and describe your results below.

[ I typed cd with a space after it, then dragged a folder from File Explorer into the terminal. The terminal automatically inserted the full path to that folder. After pressing Enter, the working directory changed to the folder I dragged in. ]

## Topic: Version Control & Git

Version control, also known as revision control, records changes to a file or set of files over time so that you can recall specific versions later. In this class, we are learning Git. Update the information below where indicated.

**1. There are three types of version control.**

[
1. Local Version Control: Files are saved and managed on one computer, often by making copies or saving different versions of the same file. It is simple, but mistakes can happen easily and files can be lost if the computer fails. 
2. Centralized Version Control (CVCS): All project files are stored on one central server. Developers connect to that server to access and update the project. This makes collaboration easier, but if the central server goes down, the team may not be able to work or access the full project history. 
3. Distributed Version Control (DVCS): Each developer has a complete copy of the repository and its history on their own computer. This makes collaboration flexible and also provides backup copies if the remote server fails. Git is an example of a distributed version control system. ]
  

**2. Using Terminal, there are also essential Git commands to know.**

List the correct Git commands to do the actions listed below in Terminal. Replace CMD with the correct command and keep or enhance the brief description.

- [git clone <"repository-url">]: Clone a repository
- [git config --gloabal user.name "Your Name"]: Set-up a global user name
- [git config --global user.email "your@email.com"]: Set-up a global email address (to match my GitHub account email)
- [git status]: Shows the current state of your directory and staging area
- [git add .]: Add modified files to the next commit
- [git commit -m " Your commit message"]: Make a commit with a new message
- [git log]: Show my commit history
- [git help]: Show Git's help screen

**3. Connecting to GitHub using Terminal.**
HTTPS is the the correct way to connect to GitHub in this course. Describe how you connect to GitHub from Terminal using this protocol. What steps do you take?

[To connect to a GitHub repository using HTTPS from Terminal, I first open the repository on GitHub and click the Code button. I make sure HTTPS is selected, then copy the repository URL. Next, I open Terminal and navigate to the folder where I want the repository stored. I then type git clone followed by the repository URL. After the repository is cloned, I use cd followed by the repository name to enter the project folder. From there, I can use commands such as git status, git add, git commit, git pull, and git push to work with the repository.

If GitHub asks me to authenticate, I sign in using the authentication method GitHub provides for HTTPS access.]

**4. Using .gitignore and Why it's Important**  
Most repositories contain a .gitignore file.

- What is the purpose of this file?
  <br>
  [The .gitignore file tells Git which files and folders it should not track or include in commits. This is useful for keeping unnecessary, temporary, system-generated, or sensitive files out of the repository.]

- What is the "**.DS_Store**" file and why would you want to ignore it?
  <br>
  [The .DS_Store file is a hidden file automatically created by macOS to store folder display settings, such as icon positions and view options. It has nothing to do with the actual project, so it should be ignored to avoid cluttering the repository with unnecessary system files.]

- What other file or folder would you want to add to a .gitignore file and why?
  <br>
  [Another file or folder I would add to .gitignore is the Visual Studio .vs folder. This folder contains local Visual Studio settings and temporary files that are specific to my computer and are not needed by other developers working with the project.]

<br>

# Reference Links

Replace the example references below with your own links and recommended resources. It is acceptable to provide multiple links for a single topic and to use material provided to you in this class. You are encouraged to link to your own independent research as well.

[Google and Reddit were the resources I found most helpful this past week. Google helped me quickly find documentation, tutorials, and examples when I needed clarification on Git, GitHub, and Markdown. Reddit was also useful because I could read discussions from other people who had similar questions or problems and see how they solved them.]

**Terminal Commands**  
[Site Address](https://www.someaddress.com/full/url/)

**Three Types of Version Control**  
[Site Address](https://www.someaddress.com/full/url/)

**Git Commands**  
[Site Address](https://www.someaddress.com/full/url/)

**Connecting to GitHub using Terminal**  
[Site Address](https://www.someaddress.com/full/url/)

**Using .gitignore and Why it's Important**  
[Site Address](https://www.someaddress.com/full/url/)
