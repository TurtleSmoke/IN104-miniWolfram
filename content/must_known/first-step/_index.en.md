+++
title = "First step"
pre = "<b>2. </b>"
weight = 10
+++

## Download the project files

You can download the provided files directly from the [GitHub repository](https://github.com/TurtleSmoke/IN104-miniWolfram.git) by
using the following command:

```bash
git clone https://github.com/TurtleSmoke/IN104-miniWolfram.git
```

## Create a new repository

After downloading the repository, the next step is to create a new private repository on your GitHub account.
Then, you'll need to update the remote URL of your local repository to link it with the newly created repository.
This can be done by executing the following commands:

```bash
git remote remove origin # Remove the remote URL of the original repository
git remote add origin <new_repository_URL> # Add the remote URL of the new repository
git push -u origin main # Push the local repository to the new repository
```

{{% notice style="warning" %}}
You **must** create a **private** repository!
{{% /notice %}}

## Adding me as a collaborator

Finally, you will need to add both me and Professor Nguyen as collaborators to your repository. To do this, navigate to the settings
of your repository and locate the "Collaborators" section. From there, click on "Add people" and enter the following
usernames:

- `TurtleSmoke`
- `nguyensaomai`

{{% notice note %}}
Please inform me once you have completed this step!
{{% /notice %}}
