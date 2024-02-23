 > As you complete each section you **must** remove the prompt text. Every *turnin* of this project includes points for formatting of this README so keep it clean and keep it up to date. 
 > Prompt text is any lines beginning with "\>"
 > Replace anything between \<...\> with your project specifics and remove angle brackets. For example, you need to name your project and replace the header right below this line with that title (no angle brackets). 
# Library Management System Project
 
# Authors
Jorge Perez(https://github.com/foreign-cobra), 
Colin Truong(https://github.com/colintruong), 
Alexander Chavez(https://github.com/AlexC111013), 
Matthew Budding(https://github.com/MatthewBudding)

## Project Description
This LMS project is especially interesting to all four group members as it has a fairly straightforward design philosophy with enough complexity to test our knowledge of important C++ concepts, algorithms, and data structures. This project will use C++ as its main programming language, as well as common data structures in object-oriented programming such as linked lists, hashtables, 
and input/output writing/reading functionalities. 

This program will be focused on user interaction, so the main input the program receives will be the user's demands. These demands include, but are not limited to:
- Signing up for an account to use the LMS
- "Borrowing" a book/list of books registered within the LMS
- Entering records of new books for future users to borrow
- "Returning" a borrowed book
- The ability to "look up" a book within the LMS database to borrow
- Settling fines for overdue books
- Retrieving details of a specified book of their choosing. This includes the book's author, ID, publication date, summary, etc...
- Reading pages of their borrowed book within the LMS

While many of the LMS' features are already listed above, they are explained in a bit more detail here. 

- A hash function will be used to generate a unique ID for the books within the database. Users will be able to "look up" a specified book using this ID. 

- A linked list will be used to generate a "reading list" for every user with an account. There will be a limit to how many books a user can borrow. Each "reading list" will be tied to a different account. 

- Books are exclusive. Books that are borrowed by one user will not be available to others. 

- New books added to the LMS by a user will be added to the hashtable. An ID will be generated for it, but users will have to input their own information for the book specifications. 

- As always, input validation will be implemented in any and all inputs.


 > ## Phase II
 > In addition to completing the "User Interface Specification" and "Class Diagram" sections below, you will need to:
 > * Create an "Epic" (note) for each feature. Place these epics in the `Product Backlog` column
 > * Complete your first *sprint planning* meeting to plan out the next 7 days of work.
 >   * Break down the "Epics" into smaller actionable user stories (i.e. smaller development tasks). Convert them into issues and assign them to team members. Place these in the `TODO` column (aka Sprint Backlog).
 >   * These cards should represent roughly 7 days worth of development time for your team. Then, once the sprint is over you should be repeating these steps to plan a new sprint, taking you until your second scrum meeting with the reader in phase III.
 > * Schedule two check-ins using Calendly. Both time slots should be during your lab on week 6. Your entire team must be present for both check-ins.
 >   * The first check-in needs to be scheduled with your lab TA. During that meeting, you will discuss your project design/class diagram from phase II.
 >   * The second check-in should be scheduled with a reader. During that meeting you will discuss:
 >     * The tasks you are planning for the first sprint
 >     * How work will be divided between the team members
## User Interface Specification
 > Include a navigation diagram for your screens and the layout of each of those screens as desribed below. For all the layouts/diagrams, you can use any tool such as PowerPoint or a drawing program. (Specification requirement is adapted from [this template](https://redirect.cs.umbc.edu/~mgrass2/cmsc345/Template_UI.doc))

### Navigation Diagram

This navigation diagram shows the entire map of navigation through the program and how we are able to get to a certain screen. Using this map, the reader can understand many of the features of the library system.

> ![image](https://github.com/cs100/final-project-mbudd003-achav239-ctruo045-jpere470/assets/117537500/71e8a236-0bdf-41ed-b397-e9aae2bbee65)


### Screen Layouts

Starting at the signup/login screen, the user is prompted to input a username and password to create an account. From there, the user is sent to the main menu, where the user has several actions to choose from. They can either look at their user profile, search for a book, or exit the program.

First, we'll talk about searching for a book. The user can either enter the title of the book (if it's in the database) or add a new book to the database. Searching for a book that's in the database requires that it is exactly the same as the title of the book as it will be case-sensitive. Once the user finds their book, the book page will display. It will give the user the option to borrow the book if it is available. If the user is already borrowing the book, the option to return or read the book will be unlocked. If it's unavailable, the user cannot do any of the three actions. This all depends on the status of the book for the user.

Next, traversing back to the main menu, we go to the user profile. From the user profile, you can check your account info, borrowed books, or book fines. Going to your account info will show you your current username and password and give you the option to change your username or password if you'd like. Doing so will automatically sign you out of the library management system and make you sign up with your changed credentials. The borrowed books page allows you to check what books you are currently borrowing, listed in alphabetical order. You may enter the number that corresponds with the book to visit that book page. Finally, the book fines page lists any fines you have from overdue books. It leads you to a page where you enter your payment information to pay off the fines.

> ![image](https://github.com/cs100/final-project-mbudd003-achav239-ctruo045-jpere470/assets/117537500/d8959f58-d13b-48c0-b908-0da38bd826f6)
> ![image](https://github.com/cs100/final-project-mbudd003-achav239-ctruo045-jpere470/assets/117537500/fa2211d4-cc17-46bb-857c-23b9414f0d59)



## Class Diagram
 > This UML Diagram covers the general format of our project, there will be 3 main classes: books, the library system, and the user. The book will store information regarding itself, specfically the author, its name, the id we store it by, and so on. The library will be the users way of accessing the books, so it will contain activites that allow the user to change the books status of whether it was borrowed or not, and to create and add new books to the system. The user will store the books that they have borrowed and be able to access them for information.
 ![image](https://github.com/cs100/final-project-mbudd003-achav239-ctruo045-jpere470/assets/116530124/9d19cff3-feb9-4556-b8d1-a02b40fafba0)

 > ## Phase III
 > You will need to schedule a check-in for the second scrum meeting with the same reader you had your first scrum meeting with (using Calendly). Your entire team must be present. This meeting will occur on week 8 during lab time.
 
 > BEFORE the meeting you should do the following:
 > * Update your class diagram from Phase II to include any feedback you received from your TA/grader.
 > * Considering the SOLID design principles, reflect back on your class diagram and think about how you can use the SOLID principles to improve your design. You should then update the README.md file by adding the following:
 >   * A new class diagram incorporating your changes after considering the SOLID principles.
 >   * For each update in your class diagram, you must explain in 3-4 sentences:
 >     * What SOLID principle(s) did you apply?
 >     * How did you apply it? i.e. describe the change.
 >     * How did this change help you write better code?
 > * Perform a new sprint plan like you did in Phase II.
 > * You should also make sure that your README file (and Project board) are up-to-date reflecting the current status of your project and the most recent class diagram. Previous versions of the README file should still be visible through your commit history.
 
> During the meeting with your reader you will discuss: 
 > * How effective your last sprint was (each member should talk about what they did)
 > * Any tasks that did not get completed last sprint, and how you took them into consideration for this sprint
 > * Any bugs you've identified and created issues for during the sprint. Do you plan on fixing them in the next sprint or are they lower priority?
 > * What tasks you are planning for this next sprint.

 
 > ## Final deliverable
 > All group members will give a demo to the reader during lab time. ou should schedule your demo on Calendly with the same reader who took your second scrum meeting. The reader will check the demo and the project GitHub repository and ask a few questions to all the team members. 
 > Before the demo, you should do the following:
 > * Complete the sections below (i.e. Screenshots, Installation/Usage, Testing)
 > * Plan one more sprint (that you will not necessarily complete before the end of the quarter). Your In-progress and In-testing columns should be empty (you are not doing more work currently) but your TODO column should have a full sprint plan in it as you have done before. This should include any known bugs (there should be some) or new features you would like to add. These should appear as issues/cards on your Project board.
 > * Make sure your README file and Project board are up-to-date reflecting the current status of your project (e.g. any changes that you have made during the project such as changes to your class diagram). Previous versions should still be visible through your commit history. 
 
 ## Screenshots
 > Screenshots of the input/output after running your application
 ## Installation/Usage
 > Instructions on installing and running your application
 ## Testing
 > How was your project tested/validated? If you used CI, you should have a "build passing" badge in this README.
 
