# Setting up a new machine to use git #

```
git config --global user.email "Jacob.Buysse@gmail.com"
git config --global user.name "Jacob Buysse"
```

Create a file named "_netrc" in your profile directory.
```
machine code.google.com login Jacob.Buysse@gmail.com password *****
```_

# Creating the initial repository #

```
git init
git remote add origin https://code.google.com/p/project-name/
```

# Getting the latest version #

```
git pull origin master
```

# Committing all pending changes #

```
git add .
git status
git commit -a -s --status -m "TODO: Commit message."
git push origin master
```