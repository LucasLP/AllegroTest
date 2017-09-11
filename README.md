<h1> AllegroTest </h1>
A simple test of Allegro 5, and how install and initialize a project.

<br><br>
Install Allegro 5 at Ubuntu <a href="https://wiki.allegro.cc/index.php?title=Install_Allegro_from_Ubuntu_PPAs"> Click Here </a>, or:
<br>
sudo add-apt-repository ppa:allegro/5.2<br>
sudo apt-get update<br>
sudo apt-get install liballegro5-dev<br>
<br>
In the project, to configure allegro library for linker, usually all allegro files will be here:<br>
/usr/lib/x86_64-linux-gnu/<br>
<br><br>
The Allegro files are:<br>
<ul>
<li>liballegro.so</li>
<li>liballegro_acodec.so</li>
<li>liballegro_audio.so</li>
<li>liballegro_color.so</li>
<li>liballegro_dialog.so</li>
<li>liballegro_font.so</li>
<li>liballegro_image.so</li>
<li>liballegro_main.so</li>
<li>liballegro_memfile.so</li>
<li>liballegro_physfs.so</li>
<li>liballegro_primitives.so</li>
<li>liballegro_ttf.so</li>
<li>liballegro_video.so</li>
</ul>

<br>
If you don't found the files, you can run (can be slow):<br>
cd /<br>
find -name "liballegro.so"<br>

