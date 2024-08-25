<?php
// Superclass Vehicle
class Vehicle {
    public $company;
    public $price;

    public function __construct($company, $price) {
        $this->company = $company;
        $this->price = $price;
    }
}

// Subclass LightMotorVehicle
class LightMotorVehicle extends Vehicle {
    public $mileage;

    public function __construct($company, $price, $mileage) {
        parent::__construct($company, $price);
        $this->mileage = $mileage;
    }
}

// Subclass HeavyMotorVehicle
class HeavyMotorVehicle extends Vehicle {
    public $capacity;

    public function __construct($company, $price, $capacity) {
        parent::__construct($company, $price);
        $this->capacity = $capacity;
    }
}

// Create 5 objects for LightMotorVehicle
$lightVehicles = [
    new LightMotorVehicle('Toyota', 20000, 15),
    new LightMotorVehicle('Honda', 18000, 17),
    new LightMotorVehicle('Ford', 22000, 14),
    new LightMotorVehicle('Chevrolet', 21000, 16),
    new LightMotorVehicle('BMW', 25000, 12)
];

// Create 5 objects for HeavyMotorVehicle
$heavyVehicles = [
    new HeavyMotorVehicle('Volvo', 50000, 10),
    new HeavyMotorVehicle('Mack', 55000, 12),
    new HeavyMotorVehicle('Kenworth', 60000, 15),
    new HeavyMotorVehicle('Scania', 65000, 14),
    new HeavyMotorVehicle('Peterbilt', 70000, 13)
];

?>

<html>
<head></head>
<body>
    <h1>Vehicle Details</h1>
    
    <h2>Light Motor Vehicles</h2>
    <table>
        <thead>
            <tr>
                <th>Company</th>
                <th>Price</th>
                <th>Mileage</th>
            </tr>
        </thead>
        <tbody>
            <?php foreach ($lightVehicles as $vehicle): ?>
                <tr>
                    <td><?php echo htmlspecialchars($vehicle->company); ?></td>
                    <td><?php echo htmlspecialchars($vehicle->price); ?></td>
                    <td><?php echo htmlspecialchars($vehicle->mileage); ?></td>
                </tr>
            <?php endforeach; ?>
        </tbody>
    </table>
    
    <h2>Heavy Motor Vehicles</h2>
    <table>
        <thead>
            <tr>
                <th>Company</th>
                <th>Price</th>
                <th>Capacity (tons)</th>
            </tr>
        </thead>
        <tbody>
            <?php foreach ($heavyVehicles as $vehicle): ?>
                <tr>
                    <td><?php echo htmlspecialchars($vehicle->company); ?></td>
                    <td><?php echo htmlspecialchars($vehicle->price); ?></td>
                    <td><?php echo htmlspecialchars($vehicle->capacity); ?></td>
                </tr>
            <?php endforeach; ?>
        </tbody>
    </table>
</body>
</html>
