// Create Engine, initialize random number generator:
Engine engine = createEngine();
// Fixed seed (reproducible simulation runs)
engine.getDefaultRandomGenerator().setSeed( 1 );
// Selection mode for simultaneous events:
engine.setSimultaneousEventsSelectionMode( Engine.EVENT_SELECTION_LIFO );
// Set stop time:
engine.setStopTime( 100 );
// Create new root object:
Main root = new Main( engine, null, null );
// TODO Setup parameters of root object here
root.setParametersToDefaultValues();
// root.arrivalrate = 123;
// ...
// Prepare Engine for simulation:
engine.start( root );
// Start simulation in fast mode:
engine.runFast();
// TODO Process results of simulation here
// traceln( "source:" );
// traceln( inspectOf( root.source ) );
// ...
// Destroy the model:
engine.stop();