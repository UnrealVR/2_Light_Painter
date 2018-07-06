# 2_Light_Painter

Section 2 of the GameDev.tv Unreal VR Course, [available on Udemy](http://gdev.tv/unrealvrgithuboffer). Understand the best practices for user interface in VR. Design and build their own spatial interfaces. Create game saving mechanisms for any game. (ref: LP_VR2)

### 1 User Interface Section Introduction ###

**In this video (objectives)…**

1. What you will get from this section.
2. A sneak peak at the section project.
3. Setting up the project.

**After watching (learning outcomes)…**

Know what we are aiming for this section.

### 2 Creating A VR Pawn Setup ###

**In this video (objectives)…**

1. Overview of the desired setup.
2. Creating the C++.
3. Hooking up the Blueprint.

**After watching (learning outcomes)…**

Have an alternative way of setting up VR Pawns.

### 3 Binding Actions To Motion Controllers ###

**In this video (objectives)…**

1. Overview of the painting architecture.
2. Creating a Stroke actor.
3. Setup the input handling.
4. Spawning a stroke.

**After watching (learning outcomes)…**

Forward hand controller actions to their actors.

### 4 3D Painting With Spline Meshes ###

**In this video (objectives)…**

1. Writing and using the interface.
2. Outlining the algorithm.
3. Creating a spline mesh.
4. Updating the end-points.

**After watching (learning outcomes)…**

Use spline meshes for 3D drawing.

### 5 Frame Rate In VR ###

**In this video (objectives)…**

1. Why frame rate matters in VR.
2. Viewing the frame rate.
3. What changes the frame rate?

**After watching (learning outcomes)…**

Why frame rate is important and how to measure it.

### 6 Performance Bottlenecks ###

**In this video (objectives)…**

1. What are bottlenecks?
2. Tools to identify bottlenecks.
3. Game, render or GPU bound?

**After watching (learning outcomes)…**

Identify CPU or GPU bottlenecks in own games.

### 7 Performance Optimisation ###

**In this video (objectives)…**

1. Likely causes of bottlenecks.
2. Identifying vertex vs pixel bound.
3. Improving the empty scene frame time.
4. Forward rendering vs deferred rendering.

**After watching (learning outcomes)…**

Diagnose common GPU issues.

### 8 Reducing DrawCalls With Instancing ###

**In this video (objectives)…**

1. Log the number of DrawCalls.
2. Recapping the Instanced Static Mesh.
3. Replacing the meshes in the stroke.

**After watching (learning outcomes)…**

Replace multiple meshes with an Instanced Static Mesh.

### 9 Rotating & Scaling Stroke Meshes ###

**In this video (objectives)…**

1. The rotation and scaling maths.
2. The code outline.
3. Rotating and scaling APIs.

**After watching (learning outcomes)…**

How to rotate and scale to fit between two points.

### 10 Instanced Mesh Materials ###

**In this video (objectives)…**

1. Importing new meshes.
2. Creating a material.
3. Enabling the material for instanced static meshes.
4. Hiding the stroke joints.

**After watching (learning outcomes)…**

How to add materials to instanced static meshes.

### 11 Saving Game State ###

**In this video (objectives)…**

1. Creating a `USaveGame` subclass.
2. Saving and Creating APIs.
3. Our `SaveGame` header file.
4. Implementing `Save` and `Create`.

**After watching (learning outcomes)…**

Be able to create and save a `SaveGame`.

### 12 Loading A SaveGame ###

**In this video (objectives)…**

1. Setup saving from user input.
2. Loading API.
3. Using the loading API.
4. Saving and loading a UPROPERTY.

**After watching (learning outcomes)…**

Load data from a save game file.

### 13 Serialising The Game State ###

**In this video (objectives)…**

1. What is the state of our level?
2. Defining the UPROPERTY.
3. The SaveGame serialising API.
4. Capture and spawn the strokes.

**After watching (learning outcomes)…**

How to serialise simple game state.

### 14 Serialising Actors To Structs ###

**In this video (objectives)…**

1. Create Stroke state struct.
2. The Stroke serialisation API.
3. Implementing serialisation.

**After watching (learning outcomes)…**

How to use structs to serialise complex state.

### 15 Renaming C++ Base Classes ###

**In this video (objectives)…**

1. Rename the HandController class.
2. Setup an `ActiveClassRedirect`.
3. Creating a base class.
4. Extracting functionality.

**After watching (learning outcomes)…**

How to rename a C++ base class and extract functionality into a super class.

### 16 Introduction To Vector Design ###

**In this video (objectives)…**

1. Introduction to the Daydream sticker sheet.
2. Importing Sketch files into Figma.
3. The basic tools in Figma.
4. Understanding the DMM.
5. Creating a simple layout.

**After watching (learning outcomes)…**

How to use Figma to create basic layouts.

### 17 Understanding Good VR Design ###

**In this video (objectives)…**

1. Critique the Daydream designs.
2. Critique you own design.

**After watching (learning outcomes)…**

How to critique user interface designs.
