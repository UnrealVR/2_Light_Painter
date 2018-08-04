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

### 18 Designing User Interface For VR ###

**In this video (objectives)…**

1. Creating a design frame.
2. Create/capture requirements.
3. Assemble a design.

**After watching (learning outcomes)…**

How to build a UI design in Figma.

### 19 Ergonomic 3D UI Layout In Unreal ###

**In this video (objectives)…**

1. Create a placeholder widget.
2. Displaying the widget in the scene.
3. Placing the widget with spline guides.
4. Scaling the widget.
5. Placing the buttons.

**After watching (learning outcomes)…**

How to accurately place UI from a design.

### 20 UI Widget Interaction In 3D ###

**In this video (objectives)…**

1. Introducing the Widget Interaction Component.
2. Creating a button to test with.
3. Setting up the Blueprints.
4. Adding a Widget Interaction Component.
5. Clicking the button.

**After watching (learning outcomes)…**

How UI selection works in VR with Unreal.

### 21 Converting A Design To UMG - Part 1 ###

**In this video (objectives)…**

1. Setting up the grid layout.
2. Exporting the card button graphics.
3. Setting up the card button.
4. Creating all the states.

**After watching (learning outcomes)…**

Converting button designs to working UMG buttons.

### 22 Converting A Design To UMG - Part 2 ###

**In this video (objectives)…**

1. Creating the action bar widget.
2. Laying out the buttons.
3. Creating the button variations.

**After watching (learning outcomes)…**

How buttons scale with their contents.

### 23 Converting A Design To UMG - Part 3 ###

**In this video (objectives)…**

1. Layout the images.
2. Exporting the graphics.

**After watching (learning outcomes)…**

How to use a horizontal layout.

### 24 Binding UPROPERTY to UMG ###

**In this video (objectives)…**

1. Add base class and reparent `PaintingGrid`.
2. Bind the Uniform Grid Panel.
3. Create blueprint interface to `AddPainting` and call it.

**After watching (learning outcomes)…**

How to bind a widget to C++.

### 25 Spawning Widgets In C++ ###

**In this video (objectives)…**

1. Introduce the APIs. (CreateWidget, GetChildAt, AddChild)
2. Creating the Card widget.
3. Spawn a widget.
4. Add to the size box.

**After watching (learning outcomes)…**

How to spawn widgets and add them to PanelWidgets.

### 26 Converting PaintingPicker to C++ ###

**In this video (objectives)…**

1. Add `PaintingPicker` C++ parent.
2. Create the essential components in C++.
3. Copy the component values.
4. Convert the blueprint to C++.

**After watching (learning outcomes)…**

Practice at reparenting Blueprints.

### 27 Naming Each Slot Uniquely ###

**In this video (objectives)…**

1. Add a SlotName variable.
2. Generate the variable on creation.
3. Create a getter for SlotName.
4. Update loading to take the SlotName.
5. Create a new `PaintingSaveGame` on every load.

**After watching (learning outcomes)…**

Using UUIDs to generate unique string names.

### 28 Iterating Over All SaveGames ###

**In this video (objectives)…**

1. Creating the `PainterSaveGameIndex`.
2. The Index API.
3. Using the API.
4. Implementing `Load()` and `Save()`.
5. Implementing `AddPainting()` and `GetPaintings()`.

**After watching (learning outcomes)…**

How to use an index to iterate over all save games.

### 29 Populating The Game List UI ###

**In this video (objectives)…**

1. Change the `AddPainting` interface.
2. Add at index.
3. Add as many paintings as there are.
4. Correct the order of slots.

**After watching (learning outcomes)…**

How to populate the UI lists.

### 30 Binding Text Widgets To C++ ###

**In this video (objectives)…**

1. Add a text box to the card.
2. Improve spacing of the grid.
3. Creating a `UPaintingGridCard` parent class.
4. Binding the `TextBlock`.

**After watching (learning outcomes)…**

How to make and bind UMG TextBlocks.

### 31 Setting TextBlock Content From C++ ###

**In this video (objectives)…**

1. Creating the `SetPaintingName` interface.
2. Calling the `SetPaintingName` interface.
3. The `UTextBlock` API and `FText`.
4. Implementing `SetPaintingName`.

**After watching (learning outcomes)…**

How to set TextBlock text in C++.

### 32 Button Actions And Splash Screens ###

**In this video (objectives)…**

1. How to use the `OpenLevel` API.
2. Binding the button `OnClicked`.
3. Opening the "Canvas" level.
4. How to get around the hanging issue.

**After watching (learning outcomes)…**

How to open levels smoothly in VR.

### 33 Parsing Level Options In GameMode ###

**In this video (objectives)…**

1. Creating a GameMode.
2. Handling the options with `InitGame`.
3. Parsing out our option.

**After watching (learning outcomes)…**

How to parse level loading options.

### 34 Loading Save Games In GameMode ###

**In this video (objectives)…**

1. Why we can't load the game in InitGame.
2. Loading the game at start.
3. Why we should hide the splash screen.

**After watching (learning outcomes)…**

When to hide a splash screen.

### 35 Handling Saving In GameMode ###

**In this video (objectives)…**

1. Creating the GameMode `SavePainting` API.
2. Calling the API.
3. Making it save.
4. Quitting to the Menu.

**After watching (learning outcomes)…**

When it's best to hide information and delegate.

### 36 Initialize - BeginPlay For Widgets ###

**In this video (objectives)…**

1. Removing the old loading and creation code.
2. When to bind buttons.
3. Create an `ActionBar` C++ parent.
4. Binding the "Add" button.
5. Binding the "Delete" button.

**After watching (learning outcomes)…**

When to use Initialize in UserWidgets.

### 37 Hooking Up The Add Functionality  ###

**In this video (objectives)…**

1. Passing a reference down to `ActionBar`.
2. Calling back up to `PaintingPicker`.
3. Create the painting and reload.

**After watching (learning outcomes)…**

How to call up to a Widget's parent.

### 38 Clearing Children of UPanelWidget ##

**In this video(objectives)…**

1. Create the API and the usage.
2. Overview of the documentation you need.
3. Iterating over the children.
4. Clearing the children of the size box.

**After watching(learning outcomes)…**

How to iterate and clear children of a `UPanelWidget`.

### 39 Connecting A LeftHandController ###

**In this video(objectives)…**

1. Create the `PaletteMenuHandController`.
2. Add and spawn a left hand controller.
3. Connecting in blueprint.
4. Setting the `MotionController` hand.

**After watching(learning outcomes)…**

Revision of the HandController architecture.

### 40 Adding Menus To Hand Controllers ###

**In this video(objectives)…**

1. Add a widget component to the controller.
2. Create and setup a widget.

**After watching(learning outcomes)…**

Revision of the widget components.

### 41 Overriding a Scene Component ###

**In this video(objectives)…**

1. Create new C++ derived class.
2. Adding a custom widget to Blueprints.
3. Overview of `IsOverInteractableWidget` API.
4. Implementing the click behaviour.

**After watching(learning outcomes)…**

How to query the interface from a `UWidgetInteractionComponent`.

### 42 Refactoring SaveAndQuit ###

**In this video(objectives)…**

1. Create `UFUNCTION` on GameMode.
2. Calling the `UFUNCTION`.
3. Moving the implementation.

**After watching(learning outcomes)…**

How to call GameMode functions from Blueprint.

### 43 Create a Pagination Dot Widget ###

**In this video(objectives)…**

1. Create the C++ parent.
2. Create the widget Blueprint and reparent.
3. Setup with the image widget.
4. Replace in the grid widget.

**After watching(learning outcomes)…**

Overview of the pagination system.

### 44 Spawning a Pagination Dot ###

**In this video(objectives)…**

1. Creating the API.
2. Temporarily calling the API.
3. Implementing the spawning.

**After watching(learning outcomes)…**

Revision of spawning widgets.

### 45 Editing UPanelSlot in C++ ###

**In this video(objectives)…**

1. What is a `UPanelSlot`.
2. Getting the right slot type.
3. Changing the padding.

**After watching(learning outcomes)…**

What a `UPanelSlot` does and how to use it.

### 46 Transparent Widgets In The World ###

**In this video(objectives)…**

1. Creating the `SetActive` API.
2. Binding the image.
3. Blend modes: transparent vs masked.
4. Implementing `SetActive`.
5. Reproducing the dots in code.

**After watching(learning outcomes)…**

The differences between blend modes and when to use them.

### 47 Calculating Number Of Pages ###

**In this video(objectives)…**

1. How to calculate number of pages.
2. Implementing `GetNumberOfSlots()`.
3. Calculating the number of slots.
4. Implementing Number of pages.

**After watching(learning outcomes)…**

How to calculate the number of pages to paginate a given number of items.
