+++
title = "Git basics"
pre = "<b>1. </b>"
weight = 5
+++

Git is a distributed version control system that allows you to track changes in your project over time. It is widely
used in the software development industry to manage source code and collaborate with other developers. A great resource
to learn more about Git is the [Official Git Book](https://git-scm.com/book/en/v2).

## Initialization

Git will always require a **repository** to work. A repository is a collection of files and directories that make up a
project. It contains the entire project history and metadata. It is basically just a folder that contains a `.git`
directory, this `.git` was created when you initialized the repository using `git init`.

If you want to start using Git in an existing project, you can initialize a new repository by running the `git init`
command in the project directory. This will create a new `.git` directory in the project folder. Then you can add a new
remote repository using the `git remote add origin <repository URL>` command. This will link your local repository to a
remote repository on GitHub for example.

You can also clone an existing repository from a remote location using the `git clone <repository URL>` command. This
will create a new directory and download all the files from the remote repository.

Git works by creating snapshots of your project files. These snapshots are called **commits**. Each commit represents a
specific version of your project. You can think of commits as checkpoints in your project history.

## Basic commands

As you could guess, to use Git you will need to understand how to create commits. But before creating a commit, you will
need to tell Git which changes you want to commit. This is done by using the `git add <files>` command. After running
this command, Git will add the changes to the **staging area**. The staging area is a place where you can prepare your
commits. You can view the **status** of your repository using the `git status` command. For example:

<div class="wrap-code highlight">
<pre>
$ echo "My great new contribution" >> my_contributions.txt
$ echo "Let's not commit it now!" >> not_now.txt
$ git add my_contributions.txt
$ git status

<span style="color:gray">\# Output from git status</span>
On branch master\
No commits yet\
Changes to be committed:
(use "git rm --cached <file>..." to unstage)
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; <span style="color:green">new file:   My great new contribution</span>\
Untracked files:
(use "git add <file>..." to include in what will be committed)
&nbsp;&nbsp;&nbsp;&nbsp;&nbsp; <span style="color:red">not_now.txt</span>
</pre></div>

The files in the **Changes to be committed** section (in green) are the files that will be included in the next commit.
The files in the **Untracked files** section (in red) are the files that are not being tracked by Git and will not be
included in the next commit.

If you want to create a commit with all the changes in the staging area, you can use the `git commit` command. You can
also add a commit message using the `-m` flag like this: `git commit -m "Add my great new contribution"`.

Now that you have created a commit, you can view the commit history using the `git log` command. This command will show
you all the commits in your repository.

Finally, you can push it to a remote repository using the `git push` command. This command will send your commits to the
remote repository, in this case, [GitHub](https://github.com/).

If you want to update your local repository with the changes from the remote repository, you can use the `git pull`
command. This command will download the changes from the remote repository and update your local repository.

## TL;DR

Remember that all git commands are executed in your project directory.

```sh
# Initialize a new repository for a new project
git init 
git remote add origin <repository URL> 
# Or clone an existing repository
git clone <repository URL>

# Do some modifications to your files
touch "My great new contribution" >> my_contributions.txt

# Add the changes to the staging area
git add my_contributions.txt

# Check the status of your repository
git status

# Create a commit from the changes in the staging area
git commit -m "Add my great new contribution"

# You can verify the commit history
git log

# Push the commit to the remote repository
git push

# Your collaborators will have to pull the changes
git pull
```

