# Building

1. Follow FPLBase installation instructions [from here](https://google.github.io/fplbase/fplbase_guide_windows.html). You will need to follow some additional steps:
  i. Because the [release page does not include the contents for dependencies](https://github.com/google/fplbase/issues/3), you will need to follow the instructions to clone the fplbase directory and initialize subdirectories. Initializing subdirectories will take a while.
  ii. Before running `cmake -G`, you will need to uinstall the [DirectX SDK](https://www.microsoft.com/en-us/download/details.aspx?id=6812). Note that you will need to [uninstall any versions of the Microsoft C++ 2010 Redistributable](https://support.microsoft.com/en-us/help/2728613/-s1023-error-when-you-install-the-directx-sdk-june-2010) before this can be installed successfully.
  iii. Run `cmake -G` by itself to get cmake to tell you what targets are available. Find the one that matches your version of Visual Studio. For me this was `Visual Studio 14 2015` since I'm using Visual Studio 2015. Then run `cmake -G <correct_version_of_Visual_Studio> .`
2. ??? (I need to test on Adam's computer to figure out what's next after this, now that there's a .sln file for my project...)
3. You're done
