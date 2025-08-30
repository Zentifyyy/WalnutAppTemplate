# Walnut App Template

This is a simple app template for [Walnut](https://github.com/TheCherno/Walnut) - unlike the example within the Walnut repository, this keeps Walnut as an external submodule and is much more sensible for actually building applications. See the [Walnut](https://github.com/TheCherno/Walnut) repository for more details.

## Getting Started

- Firstly, Make sure you have the [Vulkan SDK](https://vulkan.lunarg.com/sdk/home) installed.

- Then create your repository through GitHub templates and set the name to the name of your project.

- Then clone (download) your repository through a tool such as [GitHub Desktop](https://desktop.github.com/download) or through the command line. If you are new to git and version control i suggest looking at some [tutorials](https://docs.github.com/en/get-started/using-git).

- After you have cloned your repository, I suggest editing the ```Build-Walnut-ExampleProject.lua``` and ```WalnutApp/Build-Walnut-App.lua``` files, change WalnutApp to your applications name, you can also chang the ```WalnutApp``` folder itself and ```WalnutApp/src/WalnutApp.cpp``` to match your project. This isnt required but helps to organise your GitHub repository.

- Then run ```scripts/Setup-ExampleProject.bat``` to generate a Visual Studio Project. Navigate to the base directory and open up your ```.sln``` file and enjoy!