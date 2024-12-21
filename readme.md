# Library System - README

<div align="center">

   <video width="600" controls>
    <source src="demo/video/demoLib.mp4" type="video/mp4">

  </video>

</div>

## Features

- 📚 **Book Management**: Add, remove, edit, and list books across various categories.
- 👥 **Reader Management**: Manage and track readers, their overdue books, and fines.
- 💳 **Loan Management**: Handle book reservations.

## Motivation

This system was built to simplify the management of a library with functionalities for managing books, readers, and loans. The goal is to provide an efficient, easy-to-use, and customizable platform for libraries to handle day-to-day operations.

## Installation

### Prerequisites

Make sure you have the following installed:

- **C++ Compiler**: Ensure that your system has a C++ compiler installed.
- **Makefile**: You may need a `Makefile` to build the project.
- **Libraries**: Ensure you have the required libraries for the project (refer to the included `Library.h`, `General.h`, and other header files for dependencies).

### Steps

1. Clone the repository to your local machine:

```bash
git clone https://github.com/mightymoud/library-system.git
cd library-system
```

2. Run the application:

```bash
make run
```


## Usage

The Library System is a text-based application where you can manage books, readers, and loans. The main menu gives you access to the following options:

### Main Menu

1. **Manage Books**: Add, remove, edit, and list books.
2. **Manage Readers**: Add, edit, remove, and list readers.
3. **Manage Loans**: Handle book requests, returns, extensions, and fines.
4. **Advanced Options**: Save and load data, generate reports, and more.
5. **Exit**: Exit the program, with automatic saving of data.

### Manage Books

You can perform various actions such as:

- **Add Books**: Register new books in the library.
- **Remove Books**: Delete books by their ID.
- **Edit Books**: Update book information using the ID.
- **List Books**: View books by category or list all books.

### Manage Readers

- **Add Readers**: Register new readers into the system.
- **Edit Readers**: Modify existing reader details.
- **Remove Readers**: Delete a reader from the system.
- **List Readers**: View readers' details or search by category.

### Manage Loans

- **Request Book**: Book reservations and borrowing management.
- **Return Book**: Process book returns and calculate fines if any.
- **Extend Loans**: Extend the loan period for students and teachers.
- **Pay Fine**: Handle fine payments for overdue books.

### Advanced Options

- **Save Data**: Save the current state of books, readers, and loans to a file.
- **Load Data**: Load data from a previous session to continue from where you left off.
- **Generate Reports**: Get a report on overdue books, fines, and more.

## Inspiration

- https://www.librarymanagement.com/
- https://github.com/library-system
- https://fly.io/

## Vision

The Library System aims to:

- Simplify the management of books, readers, and loans for libraries.
- Provide a straightforward and extensible platform for library management.
- Offer robust and production-ready deployment for small to medium libraries.

## Roadmap

There are more features to come, including:

- ✅ Support for advanced filtering and searching of books and readers.
- ✅ Multi-category and multi-genre book handling.
- 🔧 Performance optimizations to scale for larger libraries.
- 🔒 Better security and data privacy with improved encryption.

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

## How to Contribute

If you want to contribute to the project, feel free to fork it and submit a pull request. Please ensure that your contributions follow the project's coding standards and provide tests where applicable.
