#include <mymod.h>

// Using the namespace RC::Unreal for Unreal Engine-related classes and methods.
using namespace RC::Unreal;

// Variables for handling Unreal Engine objects and contexts.
Unreal::AActor* myobject;                  // Pointer to a generic Unreal actor object.
Unreal::AActor* myplay;                    // Pointer to a player actor object.
Unreal::UObject* mylevel;                  // Pointer to the current level object.
FWorldContext* mywolrdcontecx;             // Pointer to the world context.
Unreal::FFrame* myscriptframePost;         // Pointer to the post-execution script frame.
UObject* myscriptframePostContext;         // Pointer to the context of the post-execution script frame.
Unreal::FFrame* myscriptframePre;          // Pointer to the pre-execution script frame.
UObject* myscriptframePreContext;          // Pointer to the context of the pre-execution script frame.
UPendingNetGame* myupendingnetgameContext; // Pointer to the pending net game context.
UFunction* postnode;                       // Pointer to the function node for post-execution.
UFunction* prenode;                        // Pointer to the function node for pre-execution.

// Constructor for the `mymod` class.
mymod::mymod()
{
    // Initialization logic for the class can be placed here.
}

// Called when Unreal Engine is initialized.
void mymod::OnUnrealInitialized()
{
    // Registering various hooks for Unreal Engine lifecycle events.
    Hook::RegisterBeginPlayPostCallback(&OnActorBeginPlay);               // Hook for actor's BeginPlay event.
    Hook::RegisterLoadMapPostCallback(&OnMapload);                        // Hook for post-map loading.
    Hook::RegisterAActorTickPostCallback(&OnactorTickCb);                 // Hook for actor tick updates.
    Hook::RegisterProcessLocalScriptFunctionPostCallback(&SciptHookPost); // Hook for post-script function execution.
    Hook::RegisterProcessLocalScriptFunctionPreCallback(&SciptHookPre);   // Hook for pre-script function execution.
    Hook::RegisterInitGameStatePostCallback(&OnGMBase);                   // Hook for post-game state initialization.

    // Logging to output that the module is hooked into the Unreal Engine lifecycle.
    Output::send<LogLevel::Verbose>(STR("mymod have Hooked into functions\n"));
}

// Placeholder for logic to run when the program starts.
void mymod::OnProgramStarted()
{
}

// Placeholder for logic to execute during updates.
void mymod::OnUpdate()
{
}

// Callback for when an actor begins play.
void mymod::OnActorBeginPlay(Unreal::AActor* Context)
{
    // Check if the actor is the player and assign to `myplay`, otherwise assign to `myobject`.
    if (Context->GetName().starts_with(STR("BP_Biped_Player_C")))
    {
        myplay = Context; // Assign player object.
    }
    else
    {
        myobject = Context; // Assign generic object.
    }
}

// Placeholder for post-tick callback for an actor.
void mymod::OnactortickPost(AActorTickCallback callback)
{
}

// Callback for when a map is loaded.
std::pair<bool, bool> mymod::OnMapload(UEngine*, FWorldContext& WorldContext, FURL URL, UPendingNetGame* PendingGame, FString& Error)
{
    // Save references to world context and pending game.
    mywolrdcontecx = &WorldContext;
    myupendingnetgameContext = PendingGame;

    // Returning default pair of false values.
    return std::pair<bool, bool>();
}

// Callback for post-script function execution.
void mymod::SciptHookPost(Unreal::UObject* Context, Unreal::FFrame& Stack, void* RESULT_DECL)
{
    myscriptframePost = &Stack;         // Save stack reference.
    myscriptframePostContext = Context; // Save context object.
    postnode = Stack.Node();            // Save the function node.
}

// Callback for pre-script function execution.
void mymod::SciptHookPre(Unreal::UObject* Context, Unreal::FFrame& Stack, void* RESULT_DECL)
{
    myscriptframePre = &Stack;          // Save stack reference.
    myscriptframePreContext = Context;  // Save context object.
    prenode = Stack.Node();             // Save the function node.
}

// Placeholder for actor tick callback logic.
void mymod::OnactorTickCb(AActor* Context, float DeltaSeconds)
{
}

// Callback for when the game state is initialized.
void mymod::OnGMBase(AGameModeBase* Context)
{
    mylevel = Context->GetLevel(); // Save the level reference.
}

// Destructor for the `mymod` class.
mymod::~mymod()
{
    // Cleanup logic for the class can be placed here.
}
