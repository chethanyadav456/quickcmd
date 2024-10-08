# Contributing to Quickcmd

We welcome contributions to **Quickcmd**! Whether you're fixing bugs, improving documentation, or adding new features, we appreciate your help.

## Getting Started

### 1. Fork the Repository
- Go to the [Quickcmd repository](https://github.com/chethanyadav456/quickcmd) and click on the "Fork" button at the top right corner of the page.

### 2. Clone the Forked Repository
After forking, clone the repository to your local machine:

```bash
git clone https://github.com/yourusername/quickcmd.git
cd quickcmd
```

### 3. Create a New Branch
Create a new branch for your changes. This ensures your main branch remains clean and you can easily make multiple contributions.

```bash
git checkout -b feature-name
```

### 4. Make Your Changes
Now that you're in your new branch, start coding your feature, fixing a bug, or improving documentation. Make sure to follow the coding standards and guidelines mentioned below.

### 5. Test Your Changes
Before committing, ensure your code runs as expected and doesn't break existing functionality. If the project includes unit tests, run them using:

```bash
# Example command, adjust as necessary based on your setup
make test
```

### 6. Commit Your Changes
Write clear and concise commit messages following these guidelines:

- Use the imperative mood in your commit message (e.g., "Fix bug" instead of "Fixed bug").
- Separate the subject from the body with a blank line.
- Limit the subject line to 50 characters.
- Reference any relevant issues or pull requests in your message.

```bash
git add .
git commit -m "Short description of changes"
```

### 7. Push to Your Branch
Push your changes to your forked repository:

```bash
git push origin feature-name
```

### 8. Create a Pull Request
Once your changes are pushed, go to the original repository on GitHub and open a Pull Request (PR). Explain the purpose of your PR, the problem it solves, and any additional context.

## Coding Standards

- **Code Style**: Follow the existing code style as closely as possible. Use consistent formatting and indentation.
- **Modular Code**: Write modular, reusable, and well-documented code. Each function should have a clear purpose.
- **Comments**: Add comments where necessary, especially to explain complex logic.
- **Documentation**: Update documentation as necessary, including adding explanations for new features and updating examples.

## Reporting Bugs

If you find a bug, please open an issue on GitHub with the following details:
- **Description**: Provide a clear and concise description of the bug.
- **Steps to Reproduce**: Include any steps needed to reproduce the issue.
- **Expected Behavior**: Explain what should happen.
- **Actual Behavior**: Explain what actually happens.

## Feature Requests

We welcome feature requests! If you have an idea for a new feature, feel free to [open an issue](https://github.com/yourusername/quickcmd/issues) with a description and use cases. Explain why this feature would be beneficial and how it fits within the project's scope.

## License

By contributing to Quickcmd, you agree that your contributions will be licensed under the same license as the project. The project is licensed under [MIT License](./LICENSE).

---
