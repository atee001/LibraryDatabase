
# Library System 
  Authors: 
  [Andrew Tee](https://github.com/atee001) [Rohan Behera](https://github.com/rohanbehera03) [Cameron Tsai](https://github.com/CJT578078)
   
## Project Description
  * Why is it important or interesting to you?
    * The ability to catagorize thousands of books is interesting as we are able to track a huge amount of data. This is a real life application of how software can benefit someone's life. A typical library catalog allows users to search for books by title, author, publisher, etc. For our project we will be developing a simple library database where the user can checkout books, find new books based on recommendations, and manage their account balance. 
  
  * What languages/tools/technologies do you plan to use? (This list may change over the course of the project)
    * We plan to use C++, vim as a text editor, and Linux as the Operating System. The user will be able to interact with the program through a terminal window using a set of predefined commands.
    
  * What will be the input/output of your project?
    * Input: Search query for books, funds, inputing books. 
    * Output: Account information, displaying books, availibility of books.
  
  * What are the two design patterns you will be using? For each design pattern you must explain in 4-5 sentences:
    * We will use strategy and composite for the searchQuery. The composite pattern is the searchOR and searchAND which contains an aggregate of the interface SearchStrat. The strategy pattern is the searchByAuthor, searchByGenre, and searchByTitle. The SearchAND and SearchOR is considered a composite since the class is a composite of Search interface pointers. The leafs are the SearchByAuthor, SearchByGenre, and SearchByTitle. The strategy pattern is allowing the user to dynamically choose which searchStrategy they want. 

## Class Diagram
[Final Project Diagram.pdf](https://github.com/cs100/final-project-rbehe002_atee001_-ctsai081/files/6574695/Final.Project.Diagram.pdf)
 
  ## Final deliverable
  All group members will give a demo to the TA during lab time. The TA will check the demo and the project GitHub repository and ask a few questions to all the team members. 
  Before the demo, you should do the following:
  * Complete the sections below (i.e. Screenshots, Installation/Usage, Testing)
  * Plan one more sprint (that you will not necessarily complete before the end of the quarter). Your In-progress and In-testing columns should be empty (you are not doing more work currently) but your TODO column should have a full sprint plan in it as you have done before. This should include any known bugs (there should be some) or new features you would like to add. These should appear as issues/cards on your Kanban board. 
 
 ## Screenshots
  Screenshots of the input/output after running your application
 ## Installation/Usage
  Click master branch. Click code and then under clone and HTTPS copy the link. Open a terminal window on your computer and type the command git clone --recursive then a space and then paste the link. Type cd final-project-rbehe002_atee001_-ctsai081 to get into the directory. Type cmake3 . and then make to compile. Then type ./driver book.txt to run the program.

 ## Testing
  Our project was test/validated with the GoogleTest C++ framework and by writing driver cpp test files.
 
