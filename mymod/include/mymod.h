#pragma once

// Includes necessary Unreal Engine and C++ standard library headers.
#include <unordered_map>       // For managing hash tables.
#include <unordered_set>       // For managing sets with hash-based lookup.
#include <vector>              // For using dynamic arrays.
#include <iostream>            // For standard I/O operations.
#include <thread>              // For multi-threading support.
#include <ranges>              // For working with range-based views.

// Unreal Engine-related includes.
#include <Unreal/FFrame.hpp>           // Frame structure for Unreal Engine script stack.
#include <Unreal/UStruct.hpp>          // Unreal Engine's struct type.
#include <Unreal/UObjectGlobals.hpp>   // Global UObject-related utilities.
#include <Unreal/UObjectArray.hpp>     // Array of UObject instances.
#include <Unreal/UFunction.hpp>        // Unreal Engine function structure.
#include <Unreal/UPackage.hpp>         // Unreal Engine package structure.
#include <Unreal/UObject.hpp>          // Base UObject class.
#include <Unreal/UClass.hpp>           // Unreal Engine's class type.
#include <Unreal/AActor.hpp>           // Actor class in Unreal Engine.
#include <Unreal/Hooks.hpp>            // Hooking into Unreal Engine lifecycle events.
#include <AGameModeBase.hpp>           // Unreal Engine GameModeBase class.
#include <FWorldContext.hpp>           // Unreal Engine's world context structure.
#include <Unreal/FString.hpp>          // Unreal Engine's string class.
#include <Unreal/Core/Containers/Array.hpp> // Unreal Engine array container.
#include <Unreal/ReflectedFunction.hpp>     // For reflected Unreal Engine functions.
#include <Unreal/Signatures.hpp>            // Unreal Engine function signatures.
#include <Unreal/Property/FObjectProperty.hpp> // Unreal Engine object property type.

// Project-specific includes.
#include <UE4SSProgram.hpp>         // UE4SS program integration.
#include <Helpers/String.hpp>       // Helper functions for string manipulation.
#include <ExceptionHandling.hpp>    // Utilities for exception handling.
#include <DynamicOutput/Output.hpp> // Dynamic output logging utilities.
#include <DynamicOutput/DynamicOutput.hpp> // Additional dynamic output tools.

using namespace RC::Unreal::Hook; // Importing hook-related functions into the current namespace.
using namespace RC::Unreal;       // Importing Unreal Engine-related types into the current namespace.

// The `mymod` class handles hooks and callbacks for Unreal Engine functions and events.
class mymod
{
public:
    // Constructor and destructor.
    mymod();  // Initializes the `mymod` instance.
    ~mymod(); // Cleans up resources used by the `mymod` instance.

    // Static functions for Unreal Engine lifecycle events.
    static void OnUnrealInitialized(); // Called when Unreal Engine is initialized.
    static void OnProgramStarted();    // Called when the program starts.
    static void OnUpdate();            // Called on every update cycle.

    // Static callback functions for Unreal Engine hooks.
    static void OnactortickPost(AActorTickCallback callback); // Post-tick callback for actors.
    static std::pair<bool, bool> OnMapload(
        UEngine*, FWorldContext& WorldContext, FURL URL, UPendingNetGame* PendingGame, FString& Error); 
        // Callback for when a map is loaded.

    static void OnActorBeginPlay(Unreal::AActor* Context); // Called when an actor begins play.

    static void SciptHookPost(Unreal::UObject* Context, Unreal::FFrame& Stack, void* RESULT_DECL); 
    // Hook for post-script function execution.

    static void SciptHookPre(Unreal::UObject* Context, Unreal::FFrame& Stack, void* RESULT_DECL); 
    // Hook for pre-script function execution.

    static void OnactorTickCb(AActor* Context, float DeltaSeconds); // Callback for actor ticking.

    static void OnGMBase(AGameModeBase* Context); // Called when the game state is initialized.

private:
    // Private members can be added here for internal class logic.
};
