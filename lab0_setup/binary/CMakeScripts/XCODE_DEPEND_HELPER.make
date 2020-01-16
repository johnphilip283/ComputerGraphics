# DO NOT EDIT
# This makefile makes sure all linkable targets are
# up-to-date with anything they link to
default:
	echo "Do not invoke directly"

# Rules to remove targets that are older than anything to which they
# link.  This forces Xcode to relink the targets from scratch.  It
# does not seem to check these dependencies itself.
PostBuild.Lab0.Debug:
/Users/johnphilip/Desktop/ComputerGraphics/lab0_setup/binary/Debug/Lab0:\
	/Users/johnphilip/Qt/5.14.0/clang_64/lib/QtOpenGL.framework/QtOpenGL\
	/Users/johnphilip/Qt/5.14.0/clang_64/lib/QtWidgets.framework/QtWidgets\
	/Users/johnphilip/Qt/5.14.0/clang_64/lib/QtGui.framework/QtGui\
	/Users/johnphilip/Qt/5.14.0/clang_64/lib/QtCore.framework/QtCore
	/bin/rm -f /Users/johnphilip/Desktop/ComputerGraphics/lab0_setup/binary/Debug/Lab0


PostBuild.Lab0.Release:
/Users/johnphilip/Desktop/ComputerGraphics/lab0_setup/binary/Release/Lab0:\
	/Users/johnphilip/Qt/5.14.0/clang_64/lib/QtOpenGL.framework/QtOpenGL\
	/Users/johnphilip/Qt/5.14.0/clang_64/lib/QtWidgets.framework/QtWidgets\
	/Users/johnphilip/Qt/5.14.0/clang_64/lib/QtGui.framework/QtGui\
	/Users/johnphilip/Qt/5.14.0/clang_64/lib/QtCore.framework/QtCore
	/bin/rm -f /Users/johnphilip/Desktop/ComputerGraphics/lab0_setup/binary/Release/Lab0


PostBuild.Lab0.MinSizeRel:
/Users/johnphilip/Desktop/ComputerGraphics/lab0_setup/binary/MinSizeRel/Lab0:\
	/Users/johnphilip/Qt/5.14.0/clang_64/lib/QtOpenGL.framework/QtOpenGL\
	/Users/johnphilip/Qt/5.14.0/clang_64/lib/QtWidgets.framework/QtWidgets\
	/Users/johnphilip/Qt/5.14.0/clang_64/lib/QtGui.framework/QtGui\
	/Users/johnphilip/Qt/5.14.0/clang_64/lib/QtCore.framework/QtCore
	/bin/rm -f /Users/johnphilip/Desktop/ComputerGraphics/lab0_setup/binary/MinSizeRel/Lab0


PostBuild.Lab0.RelWithDebInfo:
/Users/johnphilip/Desktop/ComputerGraphics/lab0_setup/binary/RelWithDebInfo/Lab0:\
	/Users/johnphilip/Qt/5.14.0/clang_64/lib/QtOpenGL.framework/QtOpenGL\
	/Users/johnphilip/Qt/5.14.0/clang_64/lib/QtWidgets.framework/QtWidgets\
	/Users/johnphilip/Qt/5.14.0/clang_64/lib/QtGui.framework/QtGui\
	/Users/johnphilip/Qt/5.14.0/clang_64/lib/QtCore.framework/QtCore
	/bin/rm -f /Users/johnphilip/Desktop/ComputerGraphics/lab0_setup/binary/RelWithDebInfo/Lab0




# For each target create a dummy ruleso the target does not have to exist
/Users/johnphilip/Qt/5.14.0/clang_64/lib/QtCore.framework/QtCore:
/Users/johnphilip/Qt/5.14.0/clang_64/lib/QtGui.framework/QtGui:
/Users/johnphilip/Qt/5.14.0/clang_64/lib/QtOpenGL.framework/QtOpenGL:
/Users/johnphilip/Qt/5.14.0/clang_64/lib/QtWidgets.framework/QtWidgets:
